#include "WaveFile.h"



WaveFile::WaveFile(const char* _filePath)
{
	FILE* opendWavFile = fopen(_filePath, "rb");
	if (opendWavFile == nullptr)
	{
		// error
		kojeomDebugLogger::MessageBoxLog(L"Open Wave file Failed!!");
		return;
	}
	size_t headerSize = sizeof(header);
	size_t readByteSize = fread(&header, 1, headerSize, opendWavFile);
	size_t dataSize = header.chunkSize - 36;
	// wav파일 헤더가 잘못된경우가 있다.
	// 일단 임시코드로 실제 오디오 데이터 길이를 계산해서 넣어버린다.
	header.subChunk_2_size = dataSize;
	rawData = new uint8_t[dataSize];
	//size_t readDataByte = fread(&rawData, 1, dataSize, opendWavFile);
	int idx = 0;
	uint8_t buffer[1];
	while (fread(&buffer, 1, 1, opendWavFile) > 0)
	{
		rawData[idx] = buffer[0];
		idx++;
	}
	fclose(opendWavFile);
}


WaveFile::~WaveFile()
{
}

uint8_t* WaveFile::GetData()
{
	return rawData;
}