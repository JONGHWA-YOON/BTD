#pragma once

typedef enum eUpgradeCommandCode
{
	UpgradeCommand_eAkey,
	UpgradeCommand_eDkey,
	UpgradeCommand_eWkey,
	UpgradeCommand_eSkey,
}eUpgradeCommandCode;

// �ʱ�ȭ ���ֱ�
void UpgradeCommand_InitUpgradeCommand();

// ���� �̿��ؼ� ���� ���� ����� �Լ�
void UpgradeCommand_CreateAnswerCommand();

// ���� ���� �Է��� �� ����ϴ� �Լ�
void UpgradeCommand_WriteMyCommand();

// ���� ���� ����ϴ� �Լ�
void UpgradeCommand_DrawAnswerCommand();

void UpgradeCommand_CheckAnswer();