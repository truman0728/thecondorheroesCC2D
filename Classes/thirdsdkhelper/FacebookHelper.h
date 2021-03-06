#ifndef __FACEBOOK_HELPER_H__
#define __FACEBOOK_HELPER_H__
#ifdef SDKBOX_ENABLED
#include "PluginFacebook/PluginFacebook.h"
#endif
#include "cocos2d.h"
#include <string>
using namespace std;
USING_NS_CC;

class FacebookHelper {
private :
	std::string _captureFilename;
public:
	//static GAHelper *INSTANCE;
	FacebookHelper() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginFacebook::init();
#endif
	}

public:
	
	void login() {
#ifdef SDKBOX_ENABLED
		if (!sdkbox::PluginFacebook::isLoggedIn())
			sdkbox::PluginFacebook::login();
#endif
	};
	void logout() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginFacebook::logout();
#endif
	};
	void isLoggedIn() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginFacebook::isLoggedIn();
#endif
};
	void requestPostPermission() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginFacebook::requestPublishPermissions({ sdkbox::FB_PERM_PUBLISH_POST });
#endif
	};
	void requestReadProfilePermisson() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginFacebook::requestReadPermissions({ sdkbox::FB_PERM_READ_PUBLIC_PROFILE, sdkbox::FB_PERM_READ_USER_FRIENDS });
#endif
	};
	void dialogPhoto(string title)
	{
#ifdef SDKBOX_ENABLED

		if (!_captureFilename.empty() && FileUtils::getInstance()->isFileExist(_captureFilename))
		{
			//CCLOG("dialog photo: %s", _captureFilename.c_str());
			sdkbox::FBShareInfo info;
			info.type = sdkbox::FB_PHOTO;
			info.title = title;
			info.image = _captureFilename;
			sdkbox::PluginFacebook::dialog(info);
		}
		else
		{
			//CCLOG("##FB capture screen first");
		}
#endif
	}
	void captureScreen()
	{
		utils::captureScreen(CC_CALLBACK_2(FacebookHelper::afterCaptureScreen, this), "screen.png");
	}

	void afterCaptureScreen(bool yes, const std::string &outputFilename)
	{
		
		if (yes)
		{
			_captureFilename = outputFilename;
		}
	}

	static FacebookHelper* getInstance() {
		static  FacebookHelper *faInstance;
		if (faInstance == nullptr) {
			faInstance = new FacebookHelper();
		}
		return faInstance;
	}
};

#endif

