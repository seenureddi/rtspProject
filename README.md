# rtspProject
RTSP Server with A Law Audio and MJPEG based on MediaLAN's code
Extends the MediaLAN code to create a RTSP server with A law audio and MJPEG. Use VLC as a client with one of the following addresses:
rtsp://127.0.0.1:8554/mjpeg/1,
rtsp://127.0.0.1:8554/mjpeg/2 and
rtsp://127.0.0.1:8554/mjpeg/3.

The first two will be the same as MediaLAN's video streams with audio tonals. The third one plays a video stream showing 
1 thru' 9 with an audio tone. Jpeg tables are created using Chuang's JpegFrameParser (included in the repository for convenience). 
Use Microsoft Visual Studio 2010 to open the project and compile.
