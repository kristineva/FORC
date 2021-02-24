#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <struct.h>
using namespace std;



void makeWaveHeader(int sampleRate, int noChannels, int bitsSample, float duration, char* inWave) {
    float noSamples = duration * sampleRate;
    int byteRate = int (sampleRate * noChannels * bitsSample/8);
    int blockAlign = int(noChannels * bitsSample/8);

    int int_field = 0;
    char wave [45];

    
    unsigned char chunkID1 = 0x52494646 & 0x000000FF;
    wave[0] = chunkID1;

    unsigned char chunkID2 = 0x52494646 & 0x0000FF00 >> 8;
    wave[1] = chunkID2;
                                                            //ChunkID: "RIFF"
    unsigned char chunkID3 = 0x52494646 & 0x00FF0000 >> 16;
    wave[2] = chunkID3;

    unsigned char chunkID4 = 0x52494646 & 0xFF000000 >> 24;
    wave[3] = chunkID4;

    wave[4] = int_field;
    wave[5] = int_field;  //ChunkSize
    wave[6] = int_field;
    wave[7] = int_field;

    unsigned char formatHeader1 = 0x57415645 & 0x000000FF;
    wave[8] = formatHeader1;

    unsigned char formatHeader2 = 0x57415645 & 0x0000FF00 >> 8;
    wave[9] = formatHeader2;
                                                                            //Format "WAVE"
    unsigned char formatHeader3 = 0x57415645 & 0x00FF0000 >> 16;
    wave[10] = formatHeader3;

    unsigned char formatHeader4 = 0x57415645 & 0xFF000000 >> 24;
    wave[11] = formatHeader4;

   
    

    unsigned char subChunk1 = 0x666d7420 & 0x000000FF;
    wave[12] = subChunk1;

    unsigned char subChunk2 = 0x666d7420 & 0x0000FF00 >> 8;
    wave[13] = subChunk2;
                                                                //SubChunk1 ID "fmt "
    unsigned char subChunk3 = 0x666d7420 & 0x00FF0000 >> 16;
    wave[14] = subChunk3;

    unsigned char subChunk4 = 0x666d7420 & 0xFF000000 >> 24;
    wave[15] = subChunk4;

    
    int formatSize = 0x1000;
    
    wave[16] = formatSize; //SubChunk1 Size

    unsigned char audioFormat1 = 0x0001 & 0x00FF;
    wave[20] = audioFormat1; //AudioFormat

    unsigned char audioFormat2 = (0x0001 & 0xFF00) >> 8;
    wave[21] = audioFormat2;

    unsigned char channelsLE1 = noChannels & 0x00FF;
    wave[22] = channelsLE1; //NumChannels

    unsigned char channelsLE2 = (noChannels & 0xFF00) >> 8;
    wave[23] = channelsLE2;


    unsigned char sampleRate1 = sampleRate & 0x000000FF;
    wave[24] = sampleRate1;

    unsigned char sampleRate2 = sampleRate & 0x0000FF00 >> 8;
    wave[25] = sampleRate2;

    unsigned char sampleRate3 = sampleRate & 0x00FF0000 >> 16;
    wave[26] = sampleRate3;

    unsigned char sampleRate4 = sampleRate & 0xFF000000 >> 24;
    wave[27] = sampleRate4;


    unsigned char byteRate1 = byteRate & 0x000000FF;
    wave[28] = byteRate1;

    unsigned char byteRate2 = byteRate & 0x0000FF00 >> 8;
    wave[29] = byteRate2;

    unsigned char byteRate3 = byteRate & 0x00FF0000 >> 16;
    wave[30] = byteRate3;

    unsigned char byteRate4 = byteRate & 0xFF000000 >> 24;
    wave[31] = byteRate4;


    unsigned char blockAlign1 = blockAlign & 0x000000FF;
    wave[32] = blockAlign1;

    unsigned char blockAlign2 = blockAlign & 0x0000FF00 >> 8;
    wave[33] = blockAlign2;


    unsigned char bitsSample1 = bitsSample & 0x000000FF;
    wave[34] = bitsSample1;

    unsigned char bitsSample2 = bitsSample & 0x0000FF00 >> 8;
    wave[35] = bitsSample2;


    int chunkSize = 4 + 8 + 16 + 8 + 0;
    
    unsigned char chunkSize1 = chunkSize & 0x000000FF;
    wave[4] = chunkSize1;

    unsigned char chunkSize2 = chunkSize & 0x0000FF00 >> 8;
    wave[5] = chunkSize2;

    unsigned char chunkSize3 = chunkSize & 0x00FF0000 >> 16;
    wave[6] = chunkSize3;

    unsigned char chunkSize4 = chunkSize & 0xFF000000 >> 24;
    wave[7] = chunkSize4;

    wave[40] = 0;
    wave[41] = 0;  //SubChunk2Size
    wave[42] = 0;
    wave[43] = 0;

    for(int i=0; i < 45; ++i) {
        inWave[i] = wave[i];
    }

}

unsigned char addSample(int sample) {
    int sample_16 = int (sample * 32767);
    unsigned char data;
    
    //data = struct.pack('<h', sample_16) í py, kann ekki
    return data;
}

int main() {
    int sampleRate = 44100;
    int freq = 440;
    float duration = 0.5;
    int noChannels = 1;

    int noSamples = int(duration * sampleRate);

    //Create header
    char waveHeader[45];
    makeWaveHeader(sampleRate, noChannels, 16, duration, waveHeader);
   
    char waveData[44100];

    //Add frequency samples
    for(int i = 0; i < noSamples; i++) {
        float sample = cos(freq * i * 3.142/sampleRate);
        waveData[i] = addSample(sample);
    }

    //Update chunk and subchunk sizes
    
    int dataBytes = int(duration * sampleRate * noChannels * 16/8);
    waveHeader[40] = dataBytes;

    dataBytes = dataBytes + 4 + 8 + 16 + 8;

    unsigned char dataBytes1 = dataBytes & 0x000000FF;
    waveHeader[4] = dataBytes1;

    unsigned char dataBytes2 = dataBytes & 0x0000FF00 >> 8;
    waveHeader[5] = dataBytes2;

    unsigned char dataBytes3 = dataBytes & 0x00FF0000 >> 16;
    waveHeader[6] = dataBytes3;

    unsigned char dataBytes4 = dataBytes & 0xFF000000 >> 24;
    waveHeader[7] = dataBytes4;


  /*  char filename [32];
    filename[0] = '\0'; */

    ofstream fout;

  /*  cout << "Enter filename";
    cin >> filename; */

    fout.open("test.wav", ios::binary);
    for (int i = 0; i< 45; i++){
        fout << waveHeader[i];
    }
    for (int i = 0; i< 44100; i++){
        fout << waveData[i];
    }

    fout.close();

    return 0;



}