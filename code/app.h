/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

#include "story.h" // story mode logic
#include "match.h" // match mode logic

#define MATCH_MODE "match"
#define STORY_MODE "story"
#define EXIT_MODE "exit"

enum {
    APP_ENABLE,
    APP_DISABLE
};

#ifdef __cplusplus
}
#endif

#endif
