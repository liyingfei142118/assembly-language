    ;��ʾ���򣨹�������dp78.asm
        section   text
        bits   16
    ;��������������Ϣ
    Signature     db   "YANG"       ;ǩ����Ϣ
    Version       dw   1            ;��ʽ�汾
    Length        dw   end_of_text  ;�������򳤶�
    Start         dw   Begin        ;����������ڵ��ƫ��
    Zoneseg       dw   0088H        ;���������������ڴ�������ʼ��ֵ
    Reserved      dd   0            ;����
    ;-------------------------------
    ;���ݲ���֮һ
    info   db    "Address:", 0      ;��ʾ��Ϣ
    ;-------------------------------
    ;���벿��
    Begin:                          ;�����������
        MOV   AX, CS
        MOV   DS, AX                ;Դ���ݶ�������һ��
        CLD                         ;�巽���־
        MOV   DX, info
        CALL  PutStr                ;��ʾ��ʾ��Ϣ
        ;
        MOV   DX, CS                ;׼����ʾ�����ڴ�����Ķ�ֵ
        MOV   CX, 4                 ;4λʮ��������
        MOV   SI, buffer            ;�ַ����������׵�ַ
    Next:
        ROL   DX, 4                 ;ѭ������4λ
        MOV   AL, DL                ;
        CALL  TOASCII               ;ת���ɶ�ӦASCII��
        MOV   [SI],AL               ;�����������
        INC   SI
        LOOP  Next                  ;��һλ
        ;
        MOV   DX, buffer            ;ȡ����ʾ�ַ����׵�ַ
        CALL  PutStr                ;��ʾ֮
        ;
        JMP  Begin1                       ;���ص����س���!!//@1
    ;-------------------------------
    PutStr:                         ;��ʾ�ַ�������0��β��
        MOV   BH, 0
        MOV   SI, DX                ;DX=�ַ�����ʼ��ַƫ��
    .LAB1:
        LODSB
        OR    AL, AL
        JZ    .LAB2
        MOV   AH, 14
        INT   10H
        JMP   .LAB1
    .LAB2:
        RET
    ;
    TOASCII:                        ;ת��Ӧʮ����������ASCII��
        AND   AL, 0FH               ;AL��4λ = ʮ��������
        ADD   AL, '0'
        CMP   AL, '9'
        SETBE BL
        DEC   BL
        AND   BL, 7
        ADD   AL, BL
        RET

Begin1:
        MOV   AL, 0                 ;ָ����ʾҳ0
        MOV   AH, 5
        INT   10H                   ;ָ����ʾҳ//@1
        ;
        CLD
        MOV   AX, CS
        MOV   DS, AX                ;���ݶ�������һ��
        MOV   SI, hello             ;ָ���ַ�����
        ;
        MOV   AX, 0B800H            ;��ʾ�洢����ֵ
        MOV   ES, AX                ;�͵�ES
        MOV   DI, (80*5+8)*2        ;��ʼ��ʾ���꣺5��8��
        ;
        MOV   AH, 47H               ;���ԣ���װ��֣�
    Lab11:
        LODSB                       ;ȡһ���ַ�
        OR    AL, AL                ;�жϽ������
        JZ    Lab22                  ;�ǣ���ת����
        STOSW                       ;���ʾ�洢��
        JMP   Lab11                  ;����
    Lab22:
    Over11:
        JMP   Over11                  ;��������ѭ��
        ;
    hello     db    "Hello,world", 0
        ;
        ;times  510 - ($-$$)  db  0  ;���0��ֱ����510�ֽ�
        ;db    55h, 0AAh             ;���2�ֽڣ�����512�ֽ�
    ;-------------------------------
    ;���ݲ���֮��
           times  1024  db  90H     ;Ϊ����ʾ�����������1024�ֽ�
    ;
    buffer db    "00000H"           ;���ڴ�Ź����ڴ�����ĵ�ַ
           db    0DH, 0AH, 0
    end_of_text:                    ;����������������ֽڳ��ȣ�