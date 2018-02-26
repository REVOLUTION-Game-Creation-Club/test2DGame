#include "WaveFile.h"

WaveFile::WaveFile(const char* _filePath){
	FILE* opendWavFile;
	auto fileErr = fopen_s(&opendWavFile, _filePath, "rb");
	// ENOENT -> ������ ���ų� ���丮�� ����.
	// �߻������� �������¿� ���� ����ó�� �ڵ�� ���Ŀ� �߰��� ����.
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
	// ûũ������� 36byte�� ���� ���� ����� ũ��.
	size_t dataSize = header.chunkSize - 36;
	// wav ���� ��� ������ ������ �͵鵵 �ִ�.
	// ���� ���ǵǾ��ִ� WaveFileHeader�� �⺻���� ����.
	// �����Ȱ͵��� ��� ó�������� ���.
	// ������ ������ wav������ �о���̸� ����, 'fmt' ûũ �κ��̴�.
	// ���� wav���ϵ��� �м��غ���, ���÷���Ʈ�� 44100�� ��κ��̾���.
	if (header.sampleRate == 0) header.sampleRate = 44100;
	// ���� ����� ������ ����� 0�̰ų� ��������ũ�⺸�� ū ������� �����ִ� ��쵵�ִ�.
	// ����, �̺κе� �Ʒ� �ڵ�� ����ó��.
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
