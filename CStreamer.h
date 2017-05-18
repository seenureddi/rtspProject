// MediaLAN 02/2013
// CRtspSession
// - JPEG packetizer and UDP/TCP based streaming

#ifndef _CStreamer_H
#define _CStreamer_H

#include <Winsock2.h>
#include <Windows.h>

class CStreamer
{
public:
    CStreamer(SOCKET aClient);
    ~CStreamer();

    void    InitTransport(u_short aRtpPort, u_short aRtcpPort, bool TCP, bool video);
    u_short GetRtpServerPort();
    u_short GetRtcpServerPort();
    u_short GetRtpAudioServerPort();
    u_short GetRtcpAudioServerPort();
    void    StreamImage(int StreamID);
    void    StreamAudio(int StreamID);

private:
    void    SendRtpPacket(char * Jpeg, int JpegLen, int Chn);
    void    SendRtpJpegPacket(char * Jpeg, int JpegLen, int width, int height, char * Tables, int TablesLen, int offset, bool End, int Chn);
    void    SendRtpAudioPacket(char * Audio, int AudioLen, int Chn);

    SOCKET  m_RtpSocket;          // RTP socket for streaming RTP packets to client
    SOCKET  m_RtcpSocket;         // RTCP socket for sending/receiving RTCP packages

    SOCKET  m_RtpAudioSocket;          // RTP socket for streaming RTP packets to client for audio
    SOCKET  m_RtcpAudioSocket;         // RTCP socket for sending/receiving RTCP packages for audio

    u_short m_RtpClientPort;      // RTP receiver port on client - for video
    u_short m_RtcpClientPort;     // RTCP receiver port on client - for video

    u_short m_RtpAudioClientPort;      // RTP receiver port on client for audio
    u_short m_RtcpAudioClientPort;     // RTCP receiver port on client for audio

    u_short m_RtpServerPort;      // RTP sender port on server 
    u_short m_RtcpServerPort;     // RTCP sender port on server

    u_short m_RtpAudioServerPort;      // RTP sender port on server for audio
    u_short m_RtcpAudioServerPort;     // RTCP sender port on server for audio

    u_short m_SequenceNumber, m_AudioSequenceNumber;
    DWORD   m_Timestamp, m_AudioTimestamp;
    int     m_SendIdx;
    bool    m_TCPTransport;
    SOCKET  m_Client;
};

#endif