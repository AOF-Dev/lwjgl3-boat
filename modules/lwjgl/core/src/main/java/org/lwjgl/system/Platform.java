/*
 * Copyright LWJGL. All rights reserved.
 * License terms: https://www.lwjgl.org/license
 */
package org.lwjgl.system;

import java.util.regex.*;

public enum Platform {

    LINUX("Linux") {
        private final Pattern SO = Pattern.compile("(?:^|/)lib\\w+[.]so(?:[.]\\d+)*$");

        @Override
        String mapLibraryName(String name) {
            if (SO.matcher(name).find()) {
                return name;
            }

            return System.mapLibraryName(name);
        }
    },
    BOAT("Boat") {
        private final Pattern SO = Pattern.compile("(?:^|/)lib\\w+[.]so(?:[.]\\d+)*$");

        @Override
        String mapLibraryName(String name) {
            if (SO.matcher(name).find()) {
                return name;
            }

            return System.mapLibraryName(name);
        }
    },
    MACOSX("macOS") {
        private final Pattern DYLIB = Pattern.compile("(?:^|/)lib\\w+(?:[.]\\d+)*[.]dylib$");

        @Override
        String mapLibraryName(String name) {
            if (DYLIB.matcher(name).find()) {
                return name;
            }

            return System.mapLibraryName(name);
        }
    },
    WINDOWS("Windows") {
        @Override
        String mapLibraryName(String name) {
            if (name.endsWith(".dll")) {
                return name;
            }

            return System.mapLibraryName(name);
        }
    };

    private static final Platform current;

    static {
        String osName = System.getProperty("os.name");
        if (osName.startsWith("Windows")) {
            current = WINDOWS;
        } else if (osName.startsWith("Linux") || osName.startsWith("FreeBSD") || osName.startsWith("SunOS") || osName.startsWith("Unix")) {
            String platformName = System.getProperty("lwjgl.platform");
            if (platformName != null && platformName.startsWith("Boat")) {
                current = BOAT;
            } else {
                current = LINUX;
            }
        } else if (osName.startsWith("Mac OS X") || osName.startsWith("Darwin")) {
            current = MACOSX;
        } else {
            throw new LinkageError("Unknown platform: " + osName);
        }
    }

    private final String name;

    Platform(String name) {
        this.name = name;
    }

    /** Returns the platform name. */
    public String getName() {
        return name;
    }

    abstract String mapLibraryName(String name);

    /** Returns the platform on which the library is running. */
    public static Platform get() {
        return current;
    }

    public static String mapLibraryNameBundled(String name) {
        return Pointer.BITS64 ? name : name + "32";
    }

}