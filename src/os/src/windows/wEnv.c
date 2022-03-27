/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define _DEFAULT_SOURCE
#include "os.h"
#include "tglobal.h"
#include "tulog.h"

extern void taosWinSocketInit();

void osInit() {
  taosSetCoreDump();
  //[3/21/2022 14:12:34 zhenjia.zhao delete]
  /*if (configDir[0] == 0) {
    strcpy(configDir, "C:/TDengine/cfg");
  }
  strcpy(tsVnodeDir, "C:/TDengine/data");
  strcpy(tsDataDir, "C:/TDengine/data");
  strcpy(tsLogDir, "C:/TDengine/log");
  strcpy(tsScriptDir, "C:/TDengine/script");
*/
  //END
  
  //[3/21/2022 14:12:16 zhenjia.zhao modified]
  if (configDir[0] == 0) {
    strcpy(configDir, "D:/TDengine/cfg");
  }
  strcpy(tsVnodeDir, "D:/TDengine/data");
  strcpy(tsDataDir, "D:/TDengine/data");
  strcpy(tsLogDir, "D:/TDengine/log");
  strcpy(tsScriptDir, "D:/TDengine/script");
  //end


  strcpy(tsDnodeDir, "");
  strcpy(tsMnodeDir, "");  
  strcpy(tsOsName, "Windows");

  const char *tmpDir = getenv("tmp");
  if (tmpDir == NULL) {
    tmpDir = getenv("temp");
  }

  if (tmpDir != NULL) {
    strcpy(tsTempDir, tmpDir);
  } else {
    strcpy(tsTempDir, "C:\\Windows\\Temp");
  }
  
  taosWinSocketInit();
}
