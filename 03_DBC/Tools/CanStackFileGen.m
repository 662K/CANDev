function CanStackFileGen(MessageInfo, CgtFolderName, CanCodeFolderName)
  
  CanTxHeaderType = 'CAN_TxHeaderTypeDef';
  TabText = '  ';

  %% CGT File Load  
  %CanStack
  CanStackCcodeFileName = 'CanStack.c';
  CanStackHcodeFileName = 'CanStack.h';
  cFilePath = fullfile(CanCodeFolderName, CanStackCcodeFileName);
  hFilePath = fullfile(CanCodeFolderName, CanStackHcodeFileName);
  
  CanStackcCgtFileName = 'CanStackCgt.c';
  CanStackhCgtFileName = 'CanStackCgt.h';
  cCgtFilePath = fullfile(CgtFolderName, CanStackcCgtFileName);
  hCgtFilePath = fullfile(CgtFolderName, CanStackhCgtFileName);
  
  CanStackCcode = fileread(cCgtFilePath);
  CanStackHcode = fileread(hCgtFilePath);
  %TxHeader
  TxHeadercCgtFileName = 'TxHeaderFuncCallCgt.c';
  TxHeaderhCgtFileName = 'TxHeaderFuncCallCgt.h';
  TxHeadercCgtFilePath = fullfile(CgtFolderName, TxHeadercCgtFileName);
  TxHeaderhCgtFilePath = fullfile(CgtFolderName, TxHeaderhCgtFileName);
  
  TxHeadercCgt = fileread(TxHeadercCgtFilePath);
  TxHeaderhCgt = fileread(TxHeaderhCgtFilePath);
  %% TxHeader GlobalVar Create

  msgTxHeaderFullCcodeGlobalVar = '';
  msgTxHeaderFullHcodeGlobalVar = '';
  
  for i = 1:length(MessageInfo)
    Name = MessageInfo(i).Name;
    msgName = ['msg_' Name];
    TxHeaderName = [msgName '_TxHeader'];
  
    % Ccode
    msgTxHeaderCcodeGlobalVar = [CanTxHeaderType ' ' TxHeaderName ';'];
    msgTxHeaderFullCcodeGlobalVar = [msgTxHeaderFullCcodeGlobalVar, ...
                                     msgTxHeaderCcodeGlobalVar, ...
                                     newline];
    
    % Hcode
    msgTxHeaderHcodeGlobalVar = ['extern ' msgTxHeaderCcodeGlobalVar];
    msgTxHeaderFullHcodeGlobalVar = [msgTxHeaderFullHcodeGlobalVar, ...
                                     msgTxHeaderHcodeGlobalVar, ...
                                     newline];
  end
  
  CanStackCcode = strrep(CanStackCcode, '<TxMsgGlobalVariablesDefine>', msgTxHeaderFullCcodeGlobalVar);
  CanStackHcode = strrep(CanStackHcode, '<TxMsgGlobalVariablesDefine>', msgTxHeaderFullHcodeGlobalVar);

  %% TxMsgInitCall

  TxHeaderInitFuncNameFullLine = '';
  
  for i = 1:length(MessageInfo)
    Name = MessageInfo(i).Name;
    msgName = ['msg_' Name];
    TxHeaderName = [msgName '_TxHeader'];
    TxHeaderInitFuncName = [TxHeaderName 'Init'];
  
    % Ccode Can Stack Init
    TxHeaderInitFuncNameLine = [TabText TxHeaderInitFuncName '();'];
    TxHeaderInitFuncNameFullLine = [TxHeaderInitFuncNameFullLine, ...
                                    TxHeaderInitFuncNameLine, ...
                                    newline];
  end
  
  CanStackCcode = strrep(CanStackCcode, '<TxMsgInitCall>', TxHeaderInitFuncNameFullLine);
  
  %% TxHeader InitFunc Code

  msgTxHeaderFullCcodeInit = '';
  msgTxHeaderFullHcodeInit = '';
  
  for i = 1:length(MessageInfo)
    Name = MessageInfo(i).Name;
    msgName = ['msg_' Name];
    TxHeaderName = [msgName '_TxHeader'];
    TxHeaderInitFuncName = [TxHeaderName 'Init'];
  
    StdId = sprintf('0x%x', MessageInfo(i).ID);
    ExtId = sprintf('0x%x', MessageInfo(i).Extended);
    DLC = num2str(MessageInfo(i).DLC);
  
    TxHeaderCcode = TxHeadercCgt;
    TxHeaderCcode = strrep(TxHeaderCcode, '<TxMsgName>', Name);
    TxHeaderCcode = strrep(TxHeaderCcode, '<TxMsgStdID>', StdId);
    TxHeaderCcode = strrep(TxHeaderCcode, '<TxMsgExtID>', ExtId);
    TxHeaderCcode = strrep(TxHeaderCcode, '<TxMsgDLC>', DLC);
  
    msgTxHeaderFullCcodeInit = [msgTxHeaderFullCcodeInit, ...
                                TxHeaderCcode, ...
                                newline, newline];
  
    TxHeaderHcode = TxHeaderhCgt;
    TxHeaderHcode = strrep(TxHeaderHcode, '<TxMsgName>', Name);
  
    msgTxHeaderFullHcodeInit = [msgTxHeaderFullHcodeInit, ...
                                TxHeaderHcode, ...
                                newline];
  end
  
  CanStackCcode = strrep(CanStackCcode, '<TxMsgInitDefine>', msgTxHeaderFullCcodeInit);
  CanStackHcode = strrep(CanStackHcode, '<TxMsgInitDefine>', msgTxHeaderFullHcodeInit);
  
  %% File Generate

  % Ccode
  fidC = fopen(cFilePath, 'w');
  fprintf(fidC, CanStackCcode);
  fclose(fidC);
  
  % Hcode
  fidH = fopen(hFilePath, 'w');
  fprintf(fidH, CanStackHcode);
  fclose(fidH);

end
