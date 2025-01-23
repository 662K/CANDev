function CanMsgTypeDefFileGen(MessageInfo, CgtFolderName, CanCodeFolderName)
  
  TabText = '  ';

  %% CGT File Load
  % CanMsgVar
  CanMsgVarCcodeFileName = 'CanMsgVar.c';
  CanMsgVarHcodeFileName = 'CanMsgVar.h';
  cFilePath = fullfile(CanCodeFolderName, CanMsgVarCcodeFileName);
  hFilePath = fullfile(CanCodeFolderName, CanMsgVarHcodeFileName);
  
  % CanMsgVarCgt
  CanMsgVarcCgtFileName = 'CanMsgVarCgt.c';
  CanMsgVarhCgtFileName = 'CanMsgVarCgt.h';
  CanMsgVarcCgtFilePath = fullfile(CgtFolderName, CanMsgVarcCgtFileName);
  CanMsgVarhCgtFilePath = fullfile(CgtFolderName, CanMsgVarhCgtFileName);

  CanMsgVarCcode = fileread(CanMsgVarcCgtFilePath);
  CanMsgVarHcode = fileread(CanMsgVarhCgtFilePath);
  
  % StructDefCgt
  StructDefhCgtFileName = 'StructDefCgt.h';
  StructDefhCgtFilePath = fullfile(CgtFolderName, StructDefhCgtFileName);
  
  StructDefCgt = fileread(StructDefhCgtFilePath);
  
  %% CanMsgStructDef
  dbcType = {'uint8', 'uint16', 'uint32', 'int8', 'int16', 'int32', 'float'};
  stdintType = {'uint8_t', 'uint16_t', 'uint32_t', 'int8_t', 'int16_t', 'int32_t', 'float'};
  TypeMap = containers.Map(dbcType, stdintType);
  lengths = cellfun(@length, stdintType);
  max_length = max(lengths);
  
  CanMsgStructDefHcode = '';
  MsgStructVarDefCcode = '';
  MsgStructVarDefHcode = '';
  for i = 1:length(MessageInfo)
    % -----------------------< Struct Define >------------------------------ %
    % 获取结构体模板
    CanMsgStructDef = StructDefCgt;
    
    % 读取当前 Msg 名称
    MsgName = MessageInfo(i).Name;
    msgTypeDefName = ['msg_' MsgName '_TypeDef'];
    
    % 读取当前 Msg 内部 Signal 信息
    MsgSigInfo = MessageInfo(i).SignalInfo;
    
    MsgSigDef = '';
    for j = 1:length(MsgSigInfo)
      % float 类型识别
      if mod(MsgSigInfo(j).Factor, 1) ~= 0
        MsgSigInfo(j).Class = 'float';
      end
      
      % 读取当前 Signal 名称
      SigName = MsgSigInfo(j).Name;
      try
        SigClass = TypeMap(MsgSigInfo(j).Class);
      catch
        error(['存在异常数据类型' MsgSigInfo(j).Class]);
      end
      
      % 空格填充对齐
      AlignLength = max_length - length(SigClass);
      AlignChar = repmat(' ',1,AlignLength);
      
      % 写入当前 Signal 信息
      MsgSigDef = [MsgSigDef TabText SigClass AlignChar ' ' SigName ';' newline];
    end
    MsgSigDef = MsgSigDef(1:end-1);

    % 替换 Struct 模板中 Signal 信息
    CanMsgStructDef = strrep(CanMsgStructDef, '<MsgSigDefine>', MsgSigDef);

    % 替换 Struct 模板中 Msg 信息
    CanMsgStructDef = strrep(CanMsgStructDef, '<MsgPackDefine>', msgTypeDefName);
    
    % 汇总 Struct 模板
    CanMsgStructDefHcode = [CanMsgStructDefHcode CanMsgStructDef newline newline];

    % -----------------------< Variant Define >------------------------------ %
    MsgStructVarName = ['msg_' MsgName];
    MsgStructVarDef = [msgTypeDefName ' ' MsgStructVarName ';'];

    MsgStructVarDefCcode = [MsgStructVarDefCcode MsgStructVarDef newline];
    MsgStructVarDefHcode = [MsgStructVarDefHcode 'extern ' MsgStructVarDef newline];
  end

  CanMsgStructDefHcode = CanMsgStructDefHcode(1:end-1);

  CanMsgVarCcode = strrep(CanMsgVarCcode, '<GlobalVariablesDefine>', MsgStructVarDefCcode);
  
  CanMsgVarHcode = strrep(CanMsgVarHcode, '<GlobalVariablesDefine>', MsgStructVarDefHcode);
  CanMsgVarHcode = strrep(CanMsgVarHcode, '<StructDefine>', CanMsgStructDefHcode);
  
  %% File Generate
  
  % Ccode
  fidC = fopen(cFilePath, 'w');
  fprintf(fidC, CanMsgVarCcode);
  fclose(fidC);

  % Hcode
  fidH = fopen(hFilePath, 'w');
  fprintf(fidH, CanMsgVarHcode);
  fclose(fidH);

end
