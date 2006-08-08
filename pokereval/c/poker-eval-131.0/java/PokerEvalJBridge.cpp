#include "include/ro_miti_poker_jni_PokerEvalBridge.h"
#include "../include/usedecks.h"
#include "../include/rules_std.h"
#include "../include/handval_low.h"

JNIEXPORT void JNICALL Java_ro_miti_poker_jni_PokerEvalBridge_test
(JNIEnv * env, jclass jc) {
	jbyteArray ret;
	jsize size;

	printf("Hello JNI World!");
	//(*env->NewByteArray(env,0);
	//(*env)->
	//return ret;
}

JNIEXPORT void JNICALL Java_ro_miti_poker_jni_PokerEvalBridge_callOmahaPrint
(JNIEnv * env, jclass jc, jstring jhand, jstring jboard) {
	char * hand = (*env)->GetStringUTFChars(env,jhand,NULL);
	char * board = (*env)->GetStringUTFChars(env,jboard,NULL);

	//(*env)->NewByteArray(env,0);
	//testOmaha8(hand,board);

	//printf("%s",hand);
}


JNIEXPORT jintArray JNICALL Java_ro_miti_poker_jni_PokerEvalBridge_callOmahaEval
(JNIEnv * env, jclass jc, jstring jhand, jstring jboard) {

	jintArray ret;

	char * hand = (*env)->GetStringUTFChars(env,jhand,NULL);
	char * board = (*env)->GetStringUTFChars(env,jboard,NULL);
	uint32 hival, lowval;
	jint buff[2];

	evalOmaha(hand,board,&hival,&lowval);

	ret = (*env)->NewIntArray(env,2);
	buff[0] = hival;
	buff[1] = lowval;
	(*env)->SetIntArrayRegion(env,ret,0,2,buff);

	//printf("%d - %d",buff[0],hival);

	return ret;
}

JNIEXPORT jstring JNICALL Java_ro_miti_poker_jni_PokerEvalBridge_stdhandToString
(JNIEnv * env, jclass jc, jint jhand) {
	char buff[80];

	StdRules_HandVal_toString(jhand,buff);

	return (*env)->NewStringUTF(env,buff);
}


JNIEXPORT jstring JNICALL Java_ro_miti_poker_jni_PokerEvalBridge_loHandToString
(JNIEnv * env, jclass jc, jint jhand) {
	char buff[80];

	LowHandVal_toString(jhand,buff);

	return (*env)->NewStringUTF(env,buff);
}

JNIEXPORT jintArray JNICALL Java_ro_miti_poker_jni_PokerEvalBridge_callOmahaEvalI
(JNIEnv * env, jclass jc, jintArray jhand, jintArray jboard) {
	jintArray ret;

	uint32 hand[4];
	uint32 board[5];
	uint32 hival, lowval;
	jint buff[2];

	(*env)->GetIntArrayRegion(env,jhand,0,4,hand);
	(*env)->GetIntArrayRegion(env,jboard,0,5,board);

	//printf("%d",board[4]);

	evalOmahaI(hand,board,&hival,&lowval);

	ret = (*env)->NewIntArray(env,2);
	buff[0] = hival;
	buff[1] = lowval;
	(*env)->SetIntArrayRegion(env,ret,0,2,buff);

	//printf("%d - %d",buff[0],hival);

	return ret;
}