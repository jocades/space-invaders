#include <functional>

class Timer {
 private:
  int _duration;
  bool _repeat;
  float _start_time = 0.0f;
  bool _active = false;
  std::function<void()> _callback;

 public:
  Timer(
    int duration,
    bool repeat = false,
    bool autostart = false,
    std::function<void()> callback = nullptr
  );
  void start();
  void stop();
  void update();
};
