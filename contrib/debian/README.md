
Debian
====================
This directory contains files used to package icd/ic-qt
for Debian-based Linux systems. If you compile icd/ic-qt yourself, there are some useful files here.

## ic: URI support ##


ic-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ic-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ic-qt binary to `/usr/bin`
and the `../../share/pixmaps/ic128.png` to `/usr/share/pixmaps`

ic-qt.protocol (KDE)

