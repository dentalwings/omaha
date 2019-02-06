// Copyright 2007-2009 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ========================================================================
//
// Kernel object names.

#ifndef OMAHA_BASE_CONST_OBJECT_NAMES_H_
#define OMAHA_BASE_CONST_OBJECT_NAMES_H_

#include <tchar.h>
#include "omaha/base/constants.h"

namespace omaha {

// The prefix to use for global names in the win32 API's.
const TCHAR* const kGlobalPrefix = _T("Global\\Omaha");

const TCHAR* const kObjectName64Suffix = _T("-x64");

const TCHAR* const kCrashPipeNamePrefix =
    _T("\\\\.\\pipe\\") SHORT_COMPANY_NAME _T("CrashServices");

// Ensures that only one instance of machine or user Omaha is trying to setup at
// a time.
const TCHAR* const kSetupMutex = _T("{A2AA3F1F-8DD9-4848-8335-54AAB70C64AF}");

// TODO(omaha3): Update this comment.
// Signals the process to exit. Currently the core and the worker listen to
// this event.
// TODO(omaha): Consider making all our processes listen to it. Maybe not the
// service, since the SCM controls the life time of the service.
const TCHAR* const kShutdownEvent =
    _T("{66D8F6BF-5CB1-462E-97E3-8C66C2EA0D8E}");

// This is for Omaha2 backwards compatibility.
// The installed Omaha3 handoff process sets an event to tell an Omaha2 setup
// worker running from the temp directory that a UI has been displayed so that
// the Omaha2 worker will not display a second UI on error. The event's name is
// passed in this environment variable name by the Omaha2 worker.
const TCHAR* const kLegacyUiDisplayedEventEnvironmentVariableName =
    _T("GOOGLE_UPDATE_UI_DISPLAYED_EVENT_NAME");

// Ensures the Core only runs one instance per machine and one instance per
// each user session.
const TCHAR* const kCoreSingleInstance =
    _T("{1B03DCC2-BB4F-4996-8FBA-DEB32F548ED3}");

// Ensures the Crash Handler only runs one instance per machine and one
// instance per each user session.
const TCHAR* const kCrashHandlerSingleInstance =
    _T("{843BBDF5-3FB7-4216-BAB5-86731C6779D8}");

// Ensures the /ua process only runs one instance per machine and one
// instance per each user session.
const TCHAR* const kUpdateAppsSingleInstance =
    _T("{2B657C16-F507-4036-87A0-71D630E0C8DC}");

// Ensures only one installer for an app is running in a session.
// The %s is replaced with the application ID.
const TCHAR* const kInstallAppSingleInstance =
    _T("%s-{679F8D62-8081-47C8-A99B-8E13610B218D}");

// Ensures the GoogleUpdate3 server only runs one instance per machine and one
// instance per each user session.
const TCHAR* const kGoogleUpdate3SingleInstance =
    _T("{183A731E-7BEF-4D2C-8CB4-F4E340924121}");

// Ensures the recovery probe only runs one instance per machine and one
// instance per each user session.
const TCHAR* const kRecoveryProbeSingleInstance =
    _T("{4DDF8E7D-95A9-4FB3-9D4A-40FCFA5DCA2E}");

// TODO(omaha): Delete Job Object code.

// Base name of job object for Setup phase 1 processes except self updates.
// These may not be running as Local System for machine installs like
// self-updates do.
const TCHAR* const kSetupPhase1NonSelfUpdateJobObject =
    _T("{208A14FA-B5DB-422E-AD8D-23AFC69D96F7}");

// Base name of job object for interactive install processes except /install.
const TCHAR* const kAppInstallJobObject =
    _T("{2C91607B-E69E-4848-993C-FF093D3D390D}");

// Base name of job object for silent processes that are okay to kill.
const TCHAR* const kSilentJobObject =
    _T("{6B88CB00-C615-4BBC-A79A-01B1A7239888}");

// Base name of job object for silent processes that should not be killed.
const TCHAR* const kSilentDoNotKillJobObject =
    _T("{C35362E2-41E0-44D7-95E1-CDC5E1E073AA}");

// The global lock to ensure that a single app is being installed for this
// user/machine at a given time.
const TCHAR* const kInstallManagerSerializer =
    _T("{0D06A8E9-0174-42BD-A3AC-452EC8B93188}");

// Serializes access to metrics stores, machine and user, respectively.
const TCHAR* const kMetricsSerializer =
    _T("{692ADF4D-9D3A-46EA-8ABB-77A96BCAFC6A}");

// Serializes access to the registry for application state.
const TCHAR* const kRegistryAccessMutex =
    _T("{BAF5A486-EBD3-460A-9F80-3E1B6054FF63}");

// Serializes opt user id generation.
const TCHAR* const kOptUserIdLock =
    _T("{675AC8CA-F07F-48E2-8BB3-F3D82D73AD76}");

// Prefix used for programs with external (in-process) updaters to signal to
// Omaha that they are currently doing an update check, and that Omaha should
// not attempt to update it at this time.  (Conversely, it's also used by Omaha
// to signal that Omaha is about to perform an update check, and that the
// in-process updater should back off.)   The app ID is appended to this string,
// and the standard prefixes for Omaha events are prepended.  For example, if
// machine Earth was performing an in-process update, it would create:
//   Global\\OmahaUpdaterRunning{74AF07D8-FB8F-4D51-8AC7-927721D56EBB} // NOLINT
// While user Chrome would create two objects:
//   Global\\OmahaS-1-5-21-39260824-743453154-142223018-386460UpdaterRunning{4DC8B4CA-1BDA-483E-B5FA-D3C12E15B62D}  // NOLINT
//   Global\\OmahaS-1-5-21-39260824-743453154-142223018-386460UpdaterRunning{8A69D345-D564-463C-AFF1-A69D9E530F96}  // NOLINT
//
// The Omaha client will check for these events and not add these apps to the
// bundle when performing an update check.  These events are also checked in
// the COM server by the worker (as part of AppStateInit::QueueUpdateCheck);
// if they are held when the worker runs, we will immediately transition to
// AppStateError with code GOOPDATE_E_APP_USING_IN_PROCESS_UPDATER.
const TCHAR* const kExternalUpdaterActivityPrefix =
    _T("UpdaterRunning");

// The name of the shared memory objects containing the serialized COM
// interface pointers exposed by the machine core.
// TODO(omaha): Rename these constants to remove "GoogleUpdate".
// TODO(omaha): Consider following the kGlobalPrefix convention with the 'G'
// for the new shared Omaha 3 name  and building this from the same #define as
// kGlobalPrefix.
const TCHAR* const kGoogleUpdate3SharedMemoryName =
    _T("Global\\") APP_NAME_IDENTIFIER _T("3");
const TCHAR* const kGoogleUpdateCoreSharedMemoryName =
    _T("Global\\") APP_NAME_IDENTIFIER _T("Core");

}  // namespace omaha

#endif  // OMAHA_BASE_CONST_OBJECT_NAMES_H_
