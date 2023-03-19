// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWebBrowser.h"

#include "SWebBrowser.h"

void UMyWebBrowser::HandleOnLoadCompleted()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Black, "Loading completed.");
}

void UMyWebBrowser::HandleOnLoadError()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Black, "Failed to load.");
}

TSharedRef<SWidget> UMyWebBrowser::RebuildWidget()
{
	if (IsDesignTime())
	{
		return Super::RebuildWidget();
	}
	WebBrowserWidget = SNew(SWebBrowser)
	.InitialURL(InitialURL)
	.ShowControls(true)
	.ShowErrorMessage(true)
	.ShowAddressBar(true)
	.OnLoadCompleted(BIND_UOBJECT_DELEGATE(FSimpleDelegate, HandleOnLoadCompleted))
	.OnLoadError(BIND_UOBJECT_DELEGATE(FSimpleDelegate, HandleOnLoadError));
	return WebBrowserWidget.ToSharedRef();
}
