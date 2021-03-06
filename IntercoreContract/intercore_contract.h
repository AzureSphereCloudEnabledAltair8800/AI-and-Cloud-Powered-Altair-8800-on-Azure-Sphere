#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "intercore_contract.h"

// NOTE: Max intercore message size is 1024 bytes. The Message block include 2 control bytes
#define MAX_MESSAGE_LENGTH	512

typedef enum  __attribute__((packed)) {
	ALTAIR_IC_UNKNOWN,
	ALTAIR_IC_ENVIRONMENT,
	ALTAIR_IC_THERMOSTAT
} INTERCORE_MSG_TYPE;

typedef struct  __attribute__((packed)) {
	float temperature;
	float pressure;
	int desired_temperature;
} INTERCORE_ENVIRONMENT_T;

typedef struct  __attribute__((packed)) {
	INTERCORE_MSG_TYPE ic_msg_type;
	uint8_t reserved;	// Must be included in message and reserved for future use
	INTERCORE_ENVIRONMENT_T environment;
} INTERCORE_ENVIRONMENT_DATA_BLOCK_T;

typedef enum  __attribute__((packed)) {
	DISK_IC_UNKNOWN,
	DISK_IC_READ,
	DISK_IC_WRITE,
	DISK_IC_CLEAR
} INTERCORE_DISK_MSG_TYPE;

typedef struct  __attribute__((packed, aligned(4))) {
	INTERCORE_DISK_MSG_TYPE disk_ic_msg_type;
	uint16_t sector_number;
	bool cached;
	bool success;
	uint8_t drive_number;
	uint8_t sector[137];
} INTERCORE_DISK_DATA_BLOCK_T;

typedef struct  __attribute__((packed, aligned(4))) {
	float x;
	float y;
	float z;
} INTERCORE_ML_CLASSIFY_BLOCK_T;

typedef enum __attribute__((packed))
{
	IC_UNKNOWN,
	IC_PREDICTION

} INTERCORE_CMD;

typedef struct __attribute__((packed, aligned(4)))
{
	INTERCORE_CMD cmd;
	float temperature;
	char PREDICTION[20];

} INTERCORE_BLOCK;

typedef struct __attribute__((packed, aligned(4)))
{
	INTERCORE_CMD cmd;
	char PREDICTION[20];

} INTERCORE_PREDICTION_BLOCK_T;