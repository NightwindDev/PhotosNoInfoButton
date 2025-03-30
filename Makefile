TARGET := iphone:clang:latest:14.0
ARCHS = arm64 arm64e

INSTALL_TARGET_PROCESSES = MobileSlideShow

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = PhotosNoInfoButton

PhotosNoInfoButton_FILES = Tweak.c
PhotosNoInfoButton_LDFLAGS = -lobjc

include $(THEOS_MAKE_PATH)/tweak.mk
