//////////////////////////////////////////////////////////////////////
/*!	@class	AquesTalk

	@brief	�K�����������G���W�� AquesTalk10

  �����L���񂩂特���g�`�f�[�^����������ɐ�������
  �o�͉����g�`�́A16KHz, 16bit,���m����,WAV�t�H�[�}�b�g�B
                  *�T���v�����O���g���́A����p�����[�^fsc�ɂ��ω�

	@author	N.Yamazaki (AQUEST)

	@date	2017/10/27	N.Yamazaki	Creation for Win
*/
//////////////////////////////////////////////////////////////////////
#if !defined(_AQUESTALK10_H_)
#define _AQUESTALK10_H_
#ifdef __cplusplus
extern "C"{
#endif

// �����p�����[�^
typedef struct _AQTK_VOICE_ {
	int bas;	// ��{�f�� F1E/F2E/M1E (0/1/2)
	int spd;	// �b�� 	50-300 default:100
	int vol;	// ���� 	0-300 default:100
	int pit;	// ���� 	20-200 default:��{�f�ЂɈˑ�
	int acc;	// �A�N�Z���g 0-200 default:��{�f�ЂɈˑ�
	int lmd;	// �����P 	0-200 default:100
	int fsc;	// �����Q(�T���v�����O���g��) 50-200 default:100
} AQTK_VOICE;

enum VoiceBase { F1E =0, F2E, M1E }; // ��{�f��

// �v���Z�b�g����                 bas  spd  vol  pit  acc  lmd  fsc
const AQTK_VOICE	gVoice_F1 = { F1E, 100, 100, 100, 100, 100, 100}; // ���� F1
const AQTK_VOICE	gVoice_F2 = { F2E, 100, 100,  77, 150, 100, 100}; // ���� F2
const AQTK_VOICE	gVoice_F3 = { F1E,  80, 100, 100, 100,  61, 148}; // ���� F3
const AQTK_VOICE	gVoice_M1 = { M1E, 100, 100,  30, 100, 100, 100}; // �j�� M1
const AQTK_VOICE	gVoice_M2 = { M1E, 105, 100,  45, 130, 120, 100}; // �j�� M2
const AQTK_VOICE	gVoice_R1 = { M1E, 100, 100,  30,  20, 190, 100}; // ���{�b�g R1
const AQTK_VOICE	gVoice_R2 = { F2E,  70, 100,  50,  50,  50, 180}; // ���{�b�g R2


/////////////////////////////////////////////
//!	�����L���񂩂特���g�`�𐶐�
//!	�����g�`�f�[�^�͓����ŗ̈�m�ۂ����B
//!	�����g�`�f�[�^�̉���͖{�֐��̌Ăяo������AquesTalk_FreeWave()�ɂčs������
//!
//! @param	pParam[in]	�����p�����[�^ (AQTK_VOICE�\���̂̃A�h���X)
//! @param	koe[in]		�����L����iSJIS NULL�I�[�j
//!	@param	pSize[out]	�������������f�[�^�̃T�C�Y[byte]�i�G���[�̏ꍇ�̓G���[�R�[�h���Ԃ�j
//!	@return	WAV�t�H�[�}�b�g�̉����f�[�^�̐擪�A�h���X�B�G���[����NULL���Ԃ�
unsigned char * __stdcall AquesTalk_Synthe(const AQTK_VOICE *pParam, const char *koe, int *pSize);

//! @param	koe[in]		�����L����iUTF8 NULL�I�[ BOM�����j
unsigned char * __stdcall AquesTalk_Synthe_Utf8(const AQTK_VOICE *pParam, const char *koe, int *pSize);

//! @param	koe[in]		�����L����iUTF16 NULL�I�[ BOM�̗L���͖��Ȃ��@�G���f�B�A���͎��s���ɏ]���j
unsigned char * __stdcall AquesTalk_Synthe_Utf16(const AQTK_VOICE *pParam, const unsigned short *koe, int *pSize);


/////////////////////////////////////////////
//!	�����f�[�^�̗̈���J��
//!	@param  wav[in]		AquesTalk_Synthe()�ŕԂ��ꂽ�A�h���X���w��
void __stdcall AquesTalk_FreeWave(unsigned char *wav);


/////////////////////////////////////////////
//!	�J�����C�Z���X�L�[�ݒ�
//!	�����g�`�𐶐�����O�Ɉ�x�Ăяo���B
//!	����ɂ��]���ł̐������Ȃ��Ȃ�B
//!	@param  key[in]		���C�Z���X�L�[���w��
//!	@return	���C�Z���X�L�[�����������0�A�������Ȃ����1���Ԃ�
//! *�L�[�̉�͂�h�����ߕs���ȃL�[�ł�0��Ԃ��ꍇ������B���̂Ƃ������͉�������Ȃ��B
int __stdcall AquesTalk_SetDevKey(const char *key);

/////////////////////////////////////////////
//!	�g�p���C�Z���X�L�[�ݒ�
//!	�����g�`�𐶐�����O�Ɉ�x�Ăяo���B
//!	�ȍ~�A���������f�[�^�Ɋ܂܂�铧�������A�g�p���C�Z���X��������擾�ς݂ɕω�����
//!	@param  key[in]		���C�Z���X�L�[���w��
//!	@return	���C�Z���X�L�[�����������0�A�������Ȃ����1���Ԃ�
//! *�L�[�̉�͂�h�����ߕs���ȃL�[�ł�0��Ԃ��ꍇ������B���̏ꍇ�A���C�Z���X���̂܂܂ł���B
int __stdcall AquesTalk_SetUsrKey(const char *key);

#ifdef __cplusplus
}
#endif
#endif // !defined(_AQUESTALK10_H_)
//  ----------------------------------------------------------------------
// !  Copyright AQUEST Corp. 2006- .  All Rights Reserved.                !
// !  An unpublished and CONFIDENTIAL work.  Reproduction, adaptation, or !
// !  translation without prior written permission is prohibited except   !
// !  as allowed under the copyright laws.                                !
//  ----------------------------------------------------------------------
