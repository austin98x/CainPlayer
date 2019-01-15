//
// Created by cain on 2018/12/28.
//

#ifndef VIDEODEVICE_H
#define VIDEODEVICE_H

#include <PlayerOption.h>
#include <renderer/Renderer.h>

class VideoDevice : public Runnable {
public:
    VideoDevice();

    virtual ~VideoDevice();

    virtual void start();

    virtual void pause();

    virtual void resume();

    virtual void stop();

    // 初始化视频纹理宽高
    virtual void onInitTexture(int width, int height, TextureFormat format, BlendMode blendMode);

    // 更新YUV数据
    virtual int onUpdateYUV(uint8_t *yData, int yPitch,
                            uint8_t *uData, int uPitch,
                            uint8_t *vData, int vPitch);

    // 更新ARGB数据
    virtual int onUpdateARGB(uint8_t *rgba, int pitch);

    // 请求渲染
    virtual int onRequestRender(FlipDirection direction);

    virtual void run();
};

#endif //VIDEODEVICE_H
