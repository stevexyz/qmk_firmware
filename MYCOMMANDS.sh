git pull https://github.com/qmk/qmk_firmware.git master

make git-submodule

make jj40:stevexyz

make 40percentclub/gherkin:stevexyz
bin/qmk flash -kb 40percentclub/gherkin -km stevexyz
(initiate programming short-circuiting two consecutive times the pins as displayed here: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/troubleshooting-and-faq)

make bm43a:stevexyz
bin/qmk flash -kb bm43a -km stevexyz

