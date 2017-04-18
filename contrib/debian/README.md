
Debian
====================
This directory contains files used to package puticd/putic-qt
for Debian-based Linux systems. If you compile puticd/putic-qt yourself, there are some useful files here.

## putic: URI support ##


putic-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install putic-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your putic-qt binary to `/usr/bin`
and the `../../share/pixmaps/putic128.png` to `/usr/share/pixmaps`

putic-qt.protocol (KDE)

