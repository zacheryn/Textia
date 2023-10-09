#pragma once

#ifndef AUDIO_H
#define AUDIO_H

#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")
#include <string>
#include <iostream>

#ifdef _XBOX //Big-Endian
#define fourccRIFF 'RIFF'
#define fourccDATA 'data'
#define fourccFMT 'fmt '
#define fourccWAVE 'WAVE'
#define fourccXWMA 'XWMA'
#define fourccDPDS 'dpds'
#endif

#ifndef _XBOX //Little-Endian
#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'
#endif

class Audio {
private:

	IXAudio2* pXAudio2 = nullptr; //Base pointer to engine
	IXAudio2MasteringVoice* pMasterVoice = nullptr; //Pointer to mastering voice, final destination for all audio
	std::string BasePath;

	//Finds the chunks of a valid audio file pulled directlt from XAudio2 documentation
	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);

	//Reads the data in a given chunk pulled directly from XAudio2 documentation
	HRESULT ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset);



public:

	//Initializes XAudio2 as per documentaion upon object creation
	//and also takes in the path to sound files
	Audio(char* path);

	//Initializes XAudio2 as per documentaion upon object creation
	//and also takes in the path to sound files
	Audio(std::string path);

	//Takes in the file name of a .wav file, volume level, and whether the sound is to loop
	//And plays the appropiate sounds in the requested fashion
	int Play(std::string filename, float volume, bool ShouldLoop);
};

#endif