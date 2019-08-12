win32 {
    CONFIG += PLATFORM_WIN
    !contains(QT_ARCH, x86_64){
        QMAKE_TARGET.arch = x86
    } else {
        QMAKE_TARGET.arch = x86_64
    }
    win32-g++ {
        CONFIG += COMPILER_GCC
    }
}

linux {
    CONFIG += PLATFORM_LINUX
    !contains(QT_ARCH, x86_64) {
        QMAKE_TARGET.arch = x86
    } else {
        QMAKE_TARGET.arch = x86_64
    }
    linux-g++ {
        CONFIG += COMPILER_GCC
    }
}

contains(QMAKE_TARGET.arch, x86_64) {
    CONFIG += PROCESSOR_x64
} else {
    CONFIG += PROCESSOR_x86
}

CONFIG(debug, release|debug) {
    CONFIG += BUILD_DEBUG
} else {
    CONFIG += BUILD_RELEASE
}
