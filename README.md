# LED Driver
LED Driver project from
<a href="https://www.amazon.com/Driven-Development-Embedded-Pragmatic-Programmers-ebook/dp/B01D3TWF5M" target="_blank">TDD
for Embedded C</a> book by <a href="https://wingman-sw.com/renaissance/" target="_blank">James W. Grenning</a>.

To build first clone this repository with --recursive option to fetch <a href="https://github.com/ThrowTheSwitch/Unity">Unity</a>. Then:
```
$ mkdir build
$ cd build
$ cmake ../
$ make
```

To test, all the above plus:
```
$ ctest -v
```
