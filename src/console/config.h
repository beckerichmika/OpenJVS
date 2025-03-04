#ifndef CONFIG_H_
#define CONFIG_H_

#include "controller/input.h"

/* Default config values */
#define DEFAULT_CONFIG_PATH "/etc/openjvs/config"
#define DEFAULT_DEBUG_LEVEL 0
#define DEFAULT_DEVICE_MAPPING_PATH "/etc/openjvs/devices/"
#define DEFAULT_DEVICE_PATH "/dev/ttyUSB0"
#define DEFAULT_GAME "generic"
#define DEFAULT_GAME_MAPPING_PATH "/etc/openjvs/games/"
#define DEFAULT_IO "sega-type-3"
#define DEFAULT_IO_PATH "/etc/openjvs/ios/"
#define DEFAULT_ROTARY_PATH "/etc/openjvs/rotary"
#define DEFAULT_SENSE_LINE_PIN 12
#define DEFAULT_SENSE_LINE_TYPE 0
#define DEFAULT_AUTO_CONTROLLER_DETECTION 1

// Needs a better name
#define USER_CONFIG_ROOT getUserConfigDir("")
#define USER_DEVICE_MAPPING_PATH getUserConfigDir("devices/")
#define USER_GAME_MAPPING_PATH getUserConfigDir("games/")
#define USER_IO_PATH getUserConfigDir("ios/")
#define USER_ROTARY_PATH getUserConfigDir("rotary")

// This editor will be used if $EDITOR is blank
#define DEFAULT_EDITOR "vi"

#define MAX_PATH_LENGTH 1024
#define MAX_LINE_LENGTH 1024

typedef struct
{
    int senseLineType;
    int senseLinePin;
    char defaultGamePath[MAX_PATH_LENGTH];
    char devicePath[MAX_PATH_LENGTH];
    int debugLevel;
    char capabilitiesPath[MAX_PATH_LENGTH];
    int autoControllerDetection;
} JVSConfig;

typedef enum
{
    JVS_CONFIG_STATUS_ERROR = 0,
    JVS_CONFIG_STATUS_SUCCESS = 1,
    JVS_CONFIG_STATUS_FILE_NOT_FOUND,
    JVS_CONFIG_STATUS_PARSE_ERROR,
} JVSConfigStatus;

JVSConfigStatus getDefaultConfig(JVSConfig *config);
JVSConfigStatus parseConfig(char *path, JVSConfig *config);
JVSConfigStatus parseInputMapping(char *path, InputMappings *inputMappings);
JVSConfigStatus parseOutputMapping(char *path, OutputMappings *outputMappings, char *configPath);
JVSConfigStatus parseRotary(char *path, int rotary, char *output);
JVSConfigStatus parseIO(char *path, JVSCapabilities *capabilities);

char *getUserConfigDir(char *dir);

#endif // CONFIG_H_
