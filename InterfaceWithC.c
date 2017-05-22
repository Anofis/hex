#include <stdlib.h>
#include <stdio.h>
#include "InterfaceWithC.h"
#include "graph.h"
#include <fcntl.h>

JNIEXPORT jint JNICALL Java_InterfaceWithC_victory
  (JNIEnv * env, jclass cl, jintArray arr){
  	jint *bjint = (*env)->GetIntArrayElements(env, arr, 0);
  	int *board = (int*) bjint;
  	return  (victory(board)*1);
  }

