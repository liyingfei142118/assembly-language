        ;��ʾ����dp61.asm
        segment   text              ;������text
        org   100H                  ;����ƫ�ƴ�100H��ʼ����
        ;
        MOV   AX, CS
        MOV   DS, AX                ;ʹ���ݶ���������ͬ
        ;
        MOV   DX, hello             ;DX=��Ϣhello�Ķ���ƫ��
        MOV   AH, 9
        INT   21H                   ;��ʾhello��ʼ���ַ�������$��β��
        ;
        MOV   AH, 4CH
        INT   21H                   ;���ز���ϵͳ
        ;
    hello     db    "Hello,world", 0DH, 0AH, '$'  ;�����ַ�����Ϣ
    ;===============================