//
// Copyright (c) 2025 Nightwind
//

#include <objc/runtime.h>

static int (*orig_locationForBarButtonItemWithIdentifier)(id, SEL, int) = NULL;
static int hook_locationForBarButtonItemWithIdentifier(id self, SEL _cmd, int identifier) {
	int infoIdentifier = 41;

	if (__builtin_available(iOS 16, *)) {
		infoIdentifier = 38;
	}

	if (identifier == infoIdentifier) {
		return 0;
	}

	return orig_locationForBarButtonItemWithIdentifier(self, _cmd, identifier);
}

__attribute__((constructor)) static void init(void) {
	const Class cls = objc_getClass("PUOneUpBarsController");
	const Method method = class_getInstanceMethod(cls, sel_getUid("_locationForBarButtonItemWithIdentifier:"));
	orig_locationForBarButtonItemWithIdentifier = (int (*)(id, SEL, int))method_getImplementation(method);
	method_setImplementation(method, (IMP)hook_locationForBarButtonItemWithIdentifier);
}