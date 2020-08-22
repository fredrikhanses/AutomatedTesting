#include "GameTest.h"
#include "AutoTest.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine.h"
#include "EngineUtils.h"
#include "Tests/AutomationEditorCommon.h"
#include "WeaponSystem_Team7/WeaponSystem_Team7Character.h"
#include "WeaponSystem_Team7/WeaponSystem_Team7GameMode.h"

// Copy of the hidden method GetAnyGameWorld() in AutomationCommon.cpp.
// Marked as temporary there, hence, this one is temporary, too.
UWorld* GetTestWorld() 
{
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& Context : WorldContexts)
	{
		if (((Context.WorldType == EWorldType::PIE) || (Context.WorldType == EWorldType::Game)) && (Context.World() != nullptr))
		{
			return Context.World();
		}
	}
	return nullptr;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNullTest, "UnitTests.NullTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FNullTest::RunTest(const FString& Parameters)
{
	TestNull("Null is null", nullptr);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathTest, "UnitTests.MathTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FMathTest::RunTest(const FString& Parameters)
{
	TestTrue("One plus one should equal 2", 1 + 1 == 2);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathTest2, "UnitTests.MathTest2", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FMathTest2::RunTest(const FString& Parameters)
{
	TestEqual("One plus one should equal 2 by equality", 1 + 1, 2);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FWorldTest, "UnitTests.WorldTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FWorldTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	TestNotNull("World exists", world);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameModeTest, "UnitTests.GameModeTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FGameModeTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	TestTrue("GameMode class is set correctly", world->GetAuthGameMode()->IsA<AWeaponSystem_Team7GameMode>());
	return true;
}

//IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCharacterTest, "UnitTests.CharacterTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
//
//bool FCharacterTest::RunTest(const FString& Parameters)
//{
//	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
//	UWorld* world = GetTestWorld();
//	TestNotNull("Essential actor is spawned", TActorIterator<AWeaponSystem_Team7Character>(world));
//	return true;
//}