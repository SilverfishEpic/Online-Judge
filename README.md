# UVa Online Judge 練習題庫

本 Repository 收錄了 [UVa Online Judge](https://onlinejudge.org/) 的程式題目練習，用於準備**大學程式能力檢定 CPE (Collegiate Programming Examination)**。

## 目錄結構

每個題目以其 UVa 題號作為資料夾名稱，例如：
```
10035/
├── main.cpp        # 解題程式碼
└── spec.txt        # 題目說明（如有）

10041/
├── main.cpp

10055/
├── main.cpp
```

## 開發環境

### 本地環境配置

為了模擬 CPE 考場環境，本專案使用以下開發工具：

- **編譯器**: Visual Studio Build Tools 2026
- **工具集**: MSVC v140 (Visual Studio 2015)
- **編譯選項**: `/Zi /EHsc /nologo`

本地環境配置細節請參考 [.vscode/tasks.json](.vscode/tasks.json)。

### UVa Online Judge 環境

所有程式碼均可在 UVa 平台使用以下編譯器選項通過編譯並 AC (Accepted)：

- **編譯器**: C++11 5.3.0 - GNU C++ Compiler
- **編譯選項**: `-lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE`

## 如何使用

### 前置需求

1. 安裝 [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/)
2. 確保已安裝 MSVC v140 工具集
3. 安裝 [Visual Studio Code](https://code.visualstudio.com/)（推薦）

### 編譯與執行

#### 使用 VS Code（推薦）

1. 開啟專案資料夾
2. 開啟要編譯的 `.cpp` 檔案
3. 按下 `Ctrl+Shift+B` 或使用命令面板執行 "Run Build Task"
4. 編譯完成後會在相同目錄下產生 `.exe` 執行檔

#### 使用命令列

```cmd
# 啟動 Visual Studio 開發者命令提示字元
cd 10035
cl.exe /Zi /EHsc /nologo /Femain.exe main.cpp
main.exe
```

### 測試

建議使用題目提供的範例輸入進行測試：

```cmd
main.exe < input.txt
```

或手動輸入測試資料。

## 編譯環境差異說明

雖然本地使用 MSVC 編譯器，UVa 使用 GCC 編譯器，但程式碼撰寫時遵循 C++11 標準，確保：

- 避免使用編譯器特定的擴充功能
- 使用標準函式庫（STL）
- 注意不同編譯器的行為差異（如未定義行為）

這樣可以保證程式碼在兩個環境下都能正確執行。

## CPE 競賽資訊

- **官方網站**: [CPE 官網](https://cpe.cse.nsysu.edu.tw/)
- **題庫來源**: [UVa Online Judge](https://onlinejudge.org/)
- **考場環境**: MSVC v140 (Visual Studio 2015)

## 參考資源

- [UVa Online Judge](https://onlinejudge.org/) - 線上評測系統
- [uHunt](https://uhunt.onlinejudge.org/) - UVa 題目追蹤工具
- [CPE 歷屆試題](https://cpe.cse.nsysu.edu.tw/newest.php)

## 授權

本專案僅供學習與練習使用。
