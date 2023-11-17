%define _unpackaged_files_terminate_build 1

Name: alterator-object-parser
Version: 0.1.0
Release: alt1

Summary: Building alterator objects library
License: GPLv2+
Group: Other
URL: https://github.com/uyraq2001/alterator-module-browser

BuildRequires(pre): rpm-macros-cmake
BuildRequires: cmake
BuildRequires: gcc-c++
BuildRequires: qt5-base-devel
BuildRequires: qt5-tools-devel
BuildRequires: qt5-base-common
BuildRequires: boost-devel-headers

Source0: %name-%version.tar

%description
Objects builder for alterator objects

%prep
%setup

%build
%cmake
%cmake_build

%install
%cmakeinstall_std

%files
%doc README.md

%changelog
* Fri Nov 17 2023 Aleksey Saprunov <sav@altlinux.org> 0.1.0-alt1
- initial build
