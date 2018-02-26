#include "WaveFile.h"

WaveFile::WaveFile(const char* _filePath){
	FILE* opendWavFile;
	auto fileErr = fopen_s(&opendWavFile, _filePath, "rb");
	// ENOENT -> 파일이 없거나 디렉토리가 없다.
	// 발생가능한 에러형태에 대한 에러처리 코드는 차후에 추가할 예정.
	if (fileErr == ENOENT) {
		// error
		kojeomDebugLogger::MessageBoxLog(L"Not found file or directory.");
		return;
	}else if (opendWavFile == nullptr){
		// error
		kojeomDebugLogger::MessageBoxLog(L"Open Wave file Failed!!");
		return;
	}
	size_t headerSize = sizeof(header);
	size_t readByteSize = fread(&header, 1, headerSize, opendWavFile);
	// 청크사이즈에서 36byte를 빼면 실제 오디오 크기.
	size_t dataSize = header.chunkSize - 36;
	// wav 파일 헤더 포멧이 변형된 것들도 있다.
	// 현재 정의되어있는 WaveFileHeader는 기본적인 형태.
	// 변형된것들은 어떻게 처리할지가 고민.
	// 변형된 포멧의 wav파일을 읽어들이면 보통, 'fmt' 청크 부분이다.
	// 여러 wav파일들을 분석해보니, 샘플레이트는 44100이 대부분이었다.
	if (header.sampleRate == 0) header.sampleRate = 44100;
	// 실제 오디오 데이터 사이즈도 0이거나 실제파일크기보다 큰 사이즈로 잡혀있는 경우도있다.
	// 따라서, 이부분도 아래 코드로 예외처리.
	if ((header.subChunk_2_size == 0) ||
		(header.subChunk_2_size > header.chunkSize)) {
		header.subChunk_2_size = dataSize;
	}
	rawData = new uint8_t[dataSize];
	ReadAudioDataFromFile(opendWavFile, rawData);
	fclose(opendWavFile);
}


WaveFile::~WaveFile(){
	delete[] rawData;
}

uint8_t* WaveFile::GetData(){
	return rawData;
}

void WaveFile::ReadAudioDataFromFile(FILE* opendFile, uint8_t* dest){
	int idx = 0;
	uint8_t buffer[1];
	while (fread(&buffer, 1, 1, opendFile) > 0){
		dest[idx] = buffer[0];
		idx++;
	}
}
