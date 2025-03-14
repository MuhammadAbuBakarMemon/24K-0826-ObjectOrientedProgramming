#include <iostream>
#include <string>

class MediaFile
{
protected:
    std::string filePath;
    double fileSize;

public:
    MediaFile(std::string filePath, double fileSize)
        : filePath(filePath), fileSize(fileSize) {}

    virtual void play()
    {
        std::cout << "Playing media file: " << filePath << std::endl;
    }

    virtual void stop()
    {
        std::cout << "Stopping media file: " << filePath << std::endl;
    }

    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile
{
protected:
    std::string resolution;

public:
    VisualMedia(std::string filePath, double fileSize, std::string resolution)
        : MediaFile(filePath, fileSize), resolution(resolution) {}

    virtual void display()
    {
        std::cout << "Displaying media with resolution: " << resolution << std::endl;
    }

    virtual ~VisualMedia() {}
};

class AudioMedia : virtual public MediaFile
{
protected:
    int sampleRate;

public:
    AudioMedia(std::string filePath, double fileSize, int sampleRate)
        : MediaFile(filePath, fileSize), sampleRate(sampleRate) {}

    virtual void playAudio()
    {
        std::cout << "Playing audio with sample rate: " << sampleRate << " Hz" << std::endl;
    }

    virtual ~AudioMedia() {}
};

class VideoFile : public VisualMedia, public AudioMedia
{
private:
    std::string videoFormat;

public:
    VideoFile(std::string filePath, double fileSize, std::string resolution, int sampleRate, std::string videoFormat)
        : MediaFile(filePath, fileSize), VisualMedia(filePath, fileSize, resolution), AudioMedia(filePath, fileSize, sampleRate), videoFormat(videoFormat) {}

    void play() override
    {
        AudioMedia::playAudio();
        VisualMedia::display();
        std::cout << "Playing video in " << videoFormat << " format." << std::endl;
    }

    void stop() override
    {
        std::cout << "Stopping video file." << std::endl;
    }

    ~VideoFile() {}
};

class ImageFile : public VisualMedia
{
public:
    ImageFile(std::string filePath, double fileSize, std::string resolution)
        : VisualMedia(filePath, fileSize, resolution) {}

    void display() override
    {
        std::cout << "Displaying image with resolution: " << resolution << std::endl;
    }

    ~ImageFile() {}
};

class AudioFile : public AudioMedia
{
public:
    AudioFile(std::string filePath, double fileSize, int sampleRate)
        : AudioMedia(filePath, fileSize, sampleRate) {}

    void playAudio() override
    {
        std::cout << "Playing audio with sample rate: " << sampleRate << " Hz" << std::endl;
    }

    ~AudioFile() {}
};

int main()
{
    MediaFile *media1 = new VideoFile("video.mp4", 100.0, "1920x1080", 44100, "MP4");
    MediaFile *media2 = new ImageFile("image.jpg", 10.0, "1024x768");
    MediaFile *media3 = new AudioFile("music.mp3", 5.0, 44100);

    media1->play();
    media2->play();
    media3->play();

    media1->stop();
    media2->stop();
    media3->stop();

    delete media1;
    delete media2;
    delete media3;

    return 0;
}
