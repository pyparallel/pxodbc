#include "pxodbc.h"
#include "errors.h"
#include "pxodbccapsule.h"

#include <pyparallel_odbc.h>

/* 0 = error, 1 = success */
int
PxOdbc_InitCapsule(PxOdbcModule_APIObject *m)
{
    HMODULE odbc32 = NULL;

    odbc32 = GetModuleHandle("odbc32");
    if (!odbc32) {
        PyErr_SetFromWindowsErr(0);
        return 0;
    }
#define _SQL_RESOLVE(n) \
    m->__##n = (LPFN_##n##)GetProcAddress(odbc32, TEXT(#n))

    _SQL_RESOLVE(SQLAllocConnect);
    _SQL_RESOLVE(SQLAllocEnv);
    _SQL_RESOLVE(SQLAllocHandle);
    _SQL_RESOLVE(SQLAllocStmt);
    _SQL_RESOLVE(SQLCancel);
    _SQL_RESOLVE(SQLCancelHandle);
    _SQL_RESOLVE(SQLCloseCursor);
    _SQL_RESOLVE(SQLColAttribute);
    _SQL_RESOLVE(SQLCompleteAsync);
    _SQL_RESOLVE(SQLConnect);
    _SQL_RESOLVE(SQLEndTran);
    _SQL_RESOLVE(SQLDescribeCol);
    _SQL_RESOLVE(SQLDisconnect);
    _SQL_RESOLVE(SQLDriverConnect);
    _SQL_RESOLVE(SQLExecute);
    _SQL_RESOLVE(SQLExecDirect);
    _SQL_RESOLVE(SQLFetch);
    _SQL_RESOLVE(SQLFetchScroll);
    _SQL_RESOLVE(SQLForeignKeys);
    _SQL_RESOLVE(SQLFreeConnect);
    _SQL_RESOLVE(SQLFreeEnv);
    _SQL_RESOLVE(SQLFreeHandle);
    _SQL_RESOLVE(SQLFreeStmt);
    _SQL_RESOLVE(SQLGetData);
    _SQL_RESOLVE(SQLGetInfo);
    _SQL_RESOLVE(SQLGetTypeInfo);
    _SQL_RESOLVE(SQLProcedures);
    _SQL_RESOLVE(SQLNumResultCols);
    _SQL_RESOLVE(SQLSetConnectAttr);
    _SQL_RESOLVE(SQLSetEnvAttr);
    _SQL_RESOLVE(SQLSetStmtAttr);
    _SQL_RESOLVE(SQLStatistics);
    _SQL_RESOLVE(SQLTables);


    //m->_DbConnectionType = (PyTypeObject *)ConnectionType;

    m->_DbGetErrorFromHandle = \
        (LPFN_DbGetErrorFromHandle)&GetErrorFromHandle;

    m->_DbRaiseErrorFromHandle = \
        (LPFN_DbRaiseErrorFromHandle)&RaiseErrorFromHandle;

    //m->_DbConnectAsync = \
    //    (LPFN_DbConnectAsync)&Connection_NewAsync;

    //m->_DbCompleteAsyncConnect = \
    //    (LPFN_DbCompleteAsyncConnect)&Connection_CompleteAsync;


    /* Do some quick egregious encapsulation violation. */
    _PyParallel_RegisterPxOdbcCapsule(m);

    return 1;
}


/* vim:set ts=8 sw=4 sts=4 tw=80 et nospell:                                  */
