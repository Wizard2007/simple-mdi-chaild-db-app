object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Simple MDI Appp'
  ClientHeight = 537
  ClientWidth = 1162
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = mmMain
  OldCreateOrder = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object mmMain: TMainMenu
    Left = 192
    Top = 120
    object miFile: TMenuItem
      Caption = 'File'
      object miExit: TMenuItem
        Action = aExit
      end
    end
    object miWindow: TMenuItem
      Caption = 'Window'
      object miOpenNewWindow: TMenuItem
        Action = aNewWindow
      end
    end
  end
  object alMain: TActionList
    Left = 264
    Top = 64
    object aExit: TAction
      Caption = 'Exit'
      OnExecute = aExitExecute
    end
    object aNewWindow: TAction
      Caption = 'New'
      OnExecute = aNewWindowExecute
    end
  end
  object tReconectScheduler: TTimer
    Enabled = False
    OnTimer = tReconectSchedulerTimer
    Left = 320
    Top = 144
  end
  object aeHandleDisconnect: TApplicationEvents
    OnException = aeHandleDisconnectException
    Left = 312
    Top = 216
  end
end
