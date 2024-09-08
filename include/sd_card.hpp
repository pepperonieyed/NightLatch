#ifndef NIGHTLATCH_INC_SD_CARD
#define NIGHTLATCH_INC_SD_CARD

#include <SPI.h>
#include <SD.h>
#include <FS.h>

#define SD_CS       10
#define SPI_MOSI    11
#define SPI_SCK     12
#define SPI_MISO    13

bool sdcard_init(void);

#endif
