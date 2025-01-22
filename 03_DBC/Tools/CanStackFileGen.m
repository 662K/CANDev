function CanStackFileGen(MessageInfo)
  
  CanTxHeaderType = 'CAN_TxHeaderTypeDef';
  TabText = '  ';

  %% CGT File Load
  CgtFolderName = 'Ccgt';
  CanCodeFolderName = 'CanConf';
  
  %CanStack
  CanStackcCodeFileName = 'CanStack.c';
  CanStackhCodeFileName = 'CanStack.h';
  cFilePath = fullfile(CanCodeFolderName, CanStackcCodeFileName);
  hFilePath = fullfile(CanCodeFolderName, CanStackhCodeFileName);
  
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

  msgTxHeaderFullcCodeGlobalVar = '';
  msgTxHeaderFullhCodeGlobalVar = '';
  
  for i = 1:length(MessageInfo)
    Name = MessageInfo(i).Name;
    msgName = ['msg_' Name];
    TxHeaderName = [msgName '_TxHeader'];
  
    % cCode
    msgTxHeadercCodeGlobalVar = [CanTxHeaderType ' ' TxHeaderName ';'];
    msgTxHeaderFullcCodeGlobalVar = [msgTxHeaderFullcCodeGlobalVar, ...
                                     msgTxHeadercCodeGlobalVar, ...
                                     newline];
    
    % hCode
    msgTxHeaderhCodeGlobalVar = ['extern ' msgTxHeadercCodeGlobalVar];
    msgTxHeaderFullhCodeGlobalVar = [msgTxHeaderFullhCodeGlobalVar, ...
                                     msgTxHeaderhCodeGlobalVar, ...
                                     newline];
  end
  
  CanStackCcode = strrep(CanStackCcode, '<TxMsgGlobalVariablesDefine>', msgTxHeaderFullcCodeGlobalVar);
  CanStackHcode = strrep(CanStackHcode, '<TxMsgGlobalVariablesDefine>', msgTxHeaderFullhCodeGlobalVar);

  %% TxMsgInitCall

  TxHeaderInitFuncNameFullLine = '';
  
  for i = 1:length(MessageInfo)
    Name = MessageInfo(i).Name;
    msgName = ['msg_' Name];
    TxHeaderName = [msgName '_TxHeader'];
    TxHeaderInitFuncName = [TxHeaderName 'Init'];
  
    % cCode Can Stack Init
    TxHeaderInitFuncNameLine = [TabText TxHeaderInitFuncName '();'];
    TxHeaderInitFuncNameFullLine = [TxHeaderInitFuncNameFullLine, ...
                                    TxHeaderInitFuncNameLine, ...
                                    newline];
  end
  
  CanStackCcode = strrep(CanStackCcode, '<TxMsgInitCall>', TxHeaderInitFuncNameFullLine);
  
  %% TxHeader InitFunc Code

  msgTxHeaderFullcCodeInit = '';
  msgTxHeaderFullhCodeInit = '';
  
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
  
    msgTxHeaderFullcCodeInit = [msgTxHeaderFullcCodeInit, ...
                                TxHeaderCcode, ...
                                newline, newline];
  
    TxHeaderHcode = TxHeaderhCgt;
    TxHeaderHcode = strrep(TxHeaderHcode, '<TxMsgName>', Name);
  
    msgTxHeaderFullhCodeInit = [msgTxHeaderFullhCodeInit, ...
                                TxHeaderHcode, ...
                                newline];
  end
  
  CanStackCcode = strrep(CanStackCcode, '<TxMsgInitDefine>', msgTxHeaderFullcCodeInit);
  CanStackHcode = strrep(CanStackHcode, '<TxMsgInitDefine>', msgTxHeaderFullhCodeInit);
  
  %% File Generate

  % cCode
  fidC = fopen(cFilePath, 'w');
  fprintf(fidC, CanStackCcode);
  fclose(fidC);
  
  % hCode
  fidH = fopen(hFilePath, 'w');
  fprintf(fidH, CanStackHcode);
  fclose(fidH);

end
