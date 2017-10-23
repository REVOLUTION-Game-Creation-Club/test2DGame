#pragma once
#include <iostream>
#include <fstream>
#include "kojeomDebugLogger.h"
struct WaveFileHeader
{
public:
	uint8_t chunkID[4]; // big endian
	uint32_t chunkSize;
	uint8_t format[4]; // big endian
	uint8_t subChunk_1_ID[4]; // big endian
	uint32_t subChunk_1_size;
	uint16_t audioFormat;
	uint16_t numChannels;
	uint32_t sampleRate;
	uint32_t byteRate;
	uint16_t blockAlign;
	uint16_t bitsPerSample;
	uint8_t subChunk_2_ID[4]; // big endian
	uint32_t subChunk_2_size;
};

using namespace std;
class WaveFile
{
public:
	WaveFile(const char* _filePath);
	~WaveFile();
	WaveFileHeader header;
	uint8_t* GetData();
private:
	uint8_t* rawData;
};

// ref : http://soundfile.sapp.org/doc/WaveFormat/
// ref : https://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file
// ref : http://forums.codeguru.com/showthread.php?460547-Reading-amp-Writing-wav-file
// ref : 