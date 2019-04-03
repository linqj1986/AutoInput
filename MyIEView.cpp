//Download by http://www.NewXing.com
// MyIEView.cpp : CMyIEView ���ʵ��
//

#include "stdafx.h"
#include "MyIE.h"

#include "MyIEDoc.h"
#include "MyIEView.h"
#include ".\myieview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "comutil.h"

// CMyIEView

IMPLEMENT_DYNCREATE(CMyIEView, CHtmlView)

BEGIN_MESSAGE_MAP(CMyIEView, CHtmlView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
	ON_COMMAND(ID_Fill, OnFill)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
END_MESSAGE_MAP()

// CMyIEView ����/����

char* KS_ANSI_to_UTF8 (const char* szAnsi)
{
	if (szAnsi == NULL)
		return NULL ;

	_bstr_t   bstrTmp (szAnsi) ;
	int       nLen = ::WideCharToMultiByte (CP_UTF8, 0, (LPCWSTR)bstrTmp, -1, NULL, 0, NULL, NULL) ;
	char      * pUTF8 = new char[nLen+1] ;
	ZeroMemory (pUTF8, nLen + 1) ;
	::WideCharToMultiByte (CP_UTF8, 0, (LPCWSTR)bstrTmp, -1, pUTF8, nLen, NULL, NULL) ;
	return pUTF8 ;
}

CMyIEView::CMyIEView()
{
	// TODO: �ڴ˴���ӹ������

}

CMyIEView::~CMyIEView()
{
}

BOOL CMyIEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CMyIEView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	Navigate2(_T("http://www.15m9.net/PageRegister?Agent=vip184"),navNoHistory|navNoWriteToCache,NULL);
	//http://freeqq2.qq.com/1.shtml 
	//http://www.15m9.net/PageRegister?Agent=vip184
}


// CMyIEView ��ӡ



// CMyIEView ���

#ifdef _DEBUG
void CMyIEView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyIEView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMyIEDoc* CMyIEView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyIEDoc)));
	return (CMyIEDoc*)m_pDocument;
}
#endif //_DEBUG

void CMyIEView::fill()
{
	IHTMLDocument2*pHTMLDocument2=(IHTMLDocument2*)(this->GetHtmlDocument());
	//pHTMLDocument2->clear();
	IHTMLElementCollection* pColl;
	IHTMLWindow2 *win;
	IHTMLFormElement *form;
	HRESULT hr;
	/*hr=pHTMLDocument2->get_links(&pColl);
	
	if(hr==S_OK)
	{
		LONG celem;
		hr=pColl->get_length(&celem);
		if(hr==S_OK)
		{
			VARIANT varIndex,var2;
			for(int i=0;i<celem;i++)
			{
				varIndex.vt=VT_UINT;
				varIndex.lVal=i;
				VariantInit(&var2);
				IDispatch* pDisp;
				hr=pColl->item(varIndex,var2,&pDisp);
				if(hr==S_OK)
				{
					BSTR bs;
					IHTMLAnchorElement*pa;
					hr=pDisp->QueryInterface(IID_IHTMLAnchorElement,(void**)&pa);
					pa->get_href(&bs);
					TRACE(bs);
					CString u(bs);
					if(u=="http://freeqq2.qq.com/2.shtml")
					{
						Navigate2(u,NULL,NULL);
					}
				}
			}
		}
	}*/
	hr=pHTMLDocument2->get_all(&pColl);
	if(hr==S_OK)
	{
		LONG celem;
		hr=pColl->get_length(&celem);
		if(hr==S_OK)
		{
			VARIANT varIndex,var2;
			for(int i=0;i<celem;i++)
			{
				varIndex.vt=VT_UINT;
				varIndex.lVal=i;
				VariantInit(&var2);
				IDispatch* pDisp;
				hr=pColl->item(varIndex,var2,&pDisp);

				if(hr==S_OK)
				{
					IHTMLElement*pElem;
					hr=pDisp->QueryInterface(IID_IHTMLElement,(void**)&pElem);
					if(hr==S_OK)
					{
						CString ts,ts1,tss;
						tss="";
						BSTR bs;
						pElem->get_tagName(&bs);
						ts=CString(bs);
						if(ts=="FORM")
						{
							hr=pDisp->QueryInterface(IID_IHTMLFormElement,(void**)&form);
							if(hr!=S_OK)
								MessageBox("error form");
							continue;

						}
						if(ts=="INPUT")
						{
							IHTMLInputElement* input;
							hr=pDisp->QueryInterface(IID_IHTMLInputElement,(void**)&input);
							input->get_name(&bs);
							ts=CString(bs);
							if(ts=="us")
							{
								ts1="zhangsh1";
								input->put_value(ts1.AllocSysString());
								TRACE("---------NICKName\n");
							}
							if(ts=="realname")
							{
								ts1="\u6211\u7684";
								_bstr_t b = ts1.AllocSysString(); 
								//char* lpszText2 = b;
								//char *szUTF8 = KS_ANSI_to_UTF8(lpszText2);
								
								input->put_value((BSTR)b);
								TRACE("-------------realname\n");
							}
							if((ts=="password1")||(ts=="password2"))
							{

								ts1="13579a";
								input->put_value(ts1.AllocSysString());
								TRACE("-----------------password\n");
							}
							if (ts=="MultiPwd")
							{
								ts1="1234";
								input->put_value(ts1.AllocSysString());
								TRACE("-------------MultiPwd\n");

							}
							if(ts=="")
							{
								input->get_value(&bs);
								tss=CString(bs);
								TRACE("%s\n",tss);
								if (tss=="�ύע��")
								{
									IHTMLElement* pElem = NULL;
									input->QueryInterface(IID_IHTMLElement, (void**)&pElem);
									pElem->click();

								}
							}
						}
						//TRACE("%d:%s\n",i,ts);
					}
				}
			}
		}
	}


}
// CMyIEView ��Ϣ�������

void CMyIEView::OnFill()
{
	// TODO: �ڴ���������������
	fill();
}

void CMyIEView::OnFileNew()
{
	// TODO: �ڴ���������������
	BSTR bs;
	CString ts="";
	IHTMLDocument2*pHTMLDocument3=(IHTMLDocument2*)(this->GetHtmlDocument());
	pHTMLDocument3->get_cookie(&bs);
	TRACE("------------------------777777777777777777------------------\n");
	TRACE(bs);
	TRACE("\n");
	pHTMLDocument3->put_cookie(ts.AllocSysString());
	pHTMLDocument3->clear();
	pHTMLDocument3->get_cookie(&bs);
	TRACE("-----------------------88888888888888888------------------\n");
	TRACE(bs);
	TRACE("\n");
	Navigate2(_T("http://freeqq2.qq.com/1.shtml"),0x4,NULL);
}


void CMyIEView::OnDownloadComplete()
{
	// TODO: Add your specialized code here and/or call the base class

	CHtmlView::OnDownloadComplete();
}


void CMyIEView::OnNavigateComplete2(LPCTSTR strURL)
{
	// TODO: Add your specialized code here and/or call the base class

	CHtmlView::OnNavigateComplete2(strURL);
}
