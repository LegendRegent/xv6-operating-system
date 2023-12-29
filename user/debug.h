//
// Created by Kyle Sun on 12/28/23.
//

#ifndef XV6_LABS_DEBUG_H
#define XV6_LABS_DEBUG_H


// Define debug levels
#define DEBUG_LEVEL_NONE    0
#define DEBUG_LEVEL_DEBUG     1
#define DEBUG_LEVEL_INFO     2

// Set the desired debug level
#define DEBUG_LEVEL DEBUG_LEVEL_INFO

// Debug macro with conditional compilation
#if DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
#define DEBUG_DEBUG(message) printf("DEBUG: %s\n", message)
#else
#define DEBUG_DEBUG(message)
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_INFO
#define DEBUG_INFO(message) printf("INFO: %s\n", message)
#else
#define DEBUG_INFO(message)
#endif

#endif //XV6_LABS_DEBUG_H
