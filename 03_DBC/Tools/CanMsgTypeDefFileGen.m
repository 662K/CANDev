function CanMsgTypeDefFileGen(MessageInfo)
  
  TabText = '  ';

  %% CGT File Load
  CgtFolderName = 'Ccgt';
  CanCodeFolderName = 'CanConf';
  
  %CanMsgTypeDef
  CanMsgTypeDefhCodeFileName = 'CanMsgTypeDef.h';
  hFilePath = fullfile(CanCodeFolderName, CanMsgTypeDefhCodeFileName);
  
  CanMsgTypeDefhCgtFileName = 'CanMsgTypeDefCgt.h';
  hCgtFilePath = fullfile(CgtFolderName, CanMsgTypeDefhCgtFileName);
  
  CanMsgTypeDefCgt = fileread(hCgtFilePath);
  
  %% CanMsgTypeDef
  CanMsgTypeDefHcode = '';

  for i = 1:length(MessageInfo)
    MsgName = MessageInfo(i).Name;
    msgTypeDefName = ['msg_' MsgName '_TypeDef'];

    CanMsgTypeDef = CanMsgTypeDefCgt;
    MsgSigInfo = MessageInfo(i).SignalInfo;
    
    MsgSigDef = '';
    for j = 1:length(MsgSigInfo)
      if mod(MsgSigInfo(j).Factor, 1) ~= 0
        MsgSigInfo(j).Class = 'float';
      end

      SigName = MsgSigInfo(j).Name;
      SigClass = MsgSigInfo(j).Class;
      
      MsgSigDef = [MsgSigDef TabText SigClass ' ' SigName newline];
    end
    MsgSigDef = MsgSigDef(1:end-1);
    CanMsgTypeDef = strrep(CanMsgTypeDef, '<MsgSigDefine>', MsgSigDef);
    CanMsgTypeDef = strrep(CanMsgTypeDef, '<MsgPackDefine>', msgTypeDefName);

    CanMsgTypeDefHcode = [CanMsgTypeDefHcode CanMsgTypeDef newline newline];
  end
  %% File Generate
  
  % hCode
  fidH = fopen(hFilePath, 'w');
  fprintf(fidH, CanMsgTypeDefHcode);
  fclose(fidH);

end
