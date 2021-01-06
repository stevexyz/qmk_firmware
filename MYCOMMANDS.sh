git fetch upstream
git merge upstream/master
make git-submodule

cd keyboards/jj40/keymaps/stevexyz/
make jj40:stevexyz
(initiate programming switching on keyboard with opposite corner key pressed)

cd keyboards/40percentclub/gherkin/keymaps/stevexyz/
make 40percentclub/gherkin:stevexyz
bin/qmk flash -kb 40percentclub/gherkin -km stevexyz
(initiate programming short-circuiting two consecutive times the pins as displayed here: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/troubleshooting-and-faq)
(figure promicro-programming.png in this directory)
issues:
on ubunto remove modem manager package
on manjaro use sudo (and maybe also remove modem manager from software) - note a single reset is enough

cd keyboards/bm43a/keymaps/stevexyz/
make bm43a:stevexyz
cd ../../../.. ; make bm43a:stevexyz ; cd -
bin/qmk flash -kb bm43a -km stevexyz
(initiate programming with keyboard RESET key)

