/*
 * Copyright LWJGL. All rights reserved.
 * License terms: https://www.lwjgl.org/license
 * MACHINE GENERATED FILE, DO NOT EDIT
 */
#include "common_tools.h"
#include "BoatLWJGL.h"
#include <dlfcn.h>

EXTERN_C_ENTER

JNIEXPORT jlong JNICALL JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlopen(jlong filenameAddress, jint mode) {
    char const *filename = (char const *)(intptr_t)filenameAddress;
    return (jlong)(intptr_t)dlopen(filename, mode);
}
JNIEXPORT jlong JNICALL Java_org_lwjgl_system_boat_DynamicLinkLoader_ndlopen(JNIEnv *__env, jclass clazz, jlong filenameAddress, jint mode) {
    UNUSED_PARAMS(__env, clazz)
    return JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlopen(filenameAddress, mode);
}

JNIEXPORT jlong JNICALL JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlerror(void) {
    return (jlong)(intptr_t)dlerror();
}
JNIEXPORT jlong JNICALL Java_org_lwjgl_system_boat_DynamicLinkLoader_ndlerror(JNIEnv *__env, jclass clazz) {
    UNUSED_PARAMS(__env, clazz)
    return JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlerror();
}

JNIEXPORT jlong JNICALL JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlsym(jlong handleAddress, jlong nameAddress) {
    void *handle = (void *)(intptr_t)handleAddress;
    char const *name = (char const *)(intptr_t)nameAddress;
    return (jlong)(intptr_t)dlsym(handle, name);
}
JNIEXPORT jlong JNICALL Java_org_lwjgl_system_boat_DynamicLinkLoader_ndlsym(JNIEnv *__env, jclass clazz, jlong handleAddress, jlong nameAddress) {
    UNUSED_PARAMS(__env, clazz)
    return JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlsym(handleAddress, nameAddress);
}

JNIEXPORT jint JNICALL JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlclose(jlong handleAddress) {
    void *handle = (void *)(intptr_t)handleAddress;
    return (jint)dlclose(handle);
}
JNIEXPORT jint JNICALL Java_org_lwjgl_system_boat_DynamicLinkLoader_ndlclose(JNIEnv *__env, jclass clazz, jlong handleAddress) {
    UNUSED_PARAMS(__env, clazz)
    return JavaCritical_org_lwjgl_system_boat_DynamicLinkLoader_ndlclose(handleAddress);
}

EXTERN_C_EXIT
