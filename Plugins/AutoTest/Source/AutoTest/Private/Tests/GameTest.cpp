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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCharacterTest, "UnitTests.CharacterTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FCharacterTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	TestNotNull("Player character is spawned", UGameplayStatics::GetPlayerCharacter(world, 0));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFireSoundTest, "UnitTests.FireSoundTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FFireSoundTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	AWeaponSystem_Team7Character* PlayerCharacter = Cast<AWeaponSystem_Team7Character>(UGameplayStatics::GetPlayerCharacter(world, 0));
	TestNotNull("FireSound is set correctly", PlayerCharacter->FireSound);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFireAnimationTest, "UnitTests.FireAnimationTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FFireAnimationTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	AWeaponSystem_Team7Character* PlayerCharacter = Cast<AWeaponSystem_Team7Character>(UGameplayStatics::GetPlayerCharacter(world, 0));
	TestNotNull("FireAnimation is set correctly", PlayerCharacter->FireAnimation);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFirstPersonMeshTest, "UnitTests.FirstPersonMeshTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FFirstPersonMeshTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	AWeaponSystem_Team7Character* PlayerCharacter = Cast<AWeaponSystem_Team7Character>(UGameplayStatics::GetPlayerCharacter(world, 0));
	TestNotNull("FirstPersonMesh is set correctly", PlayerCharacter->Mesh1P);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFirstPersonGunTest, "UnitTests.FirstPersonGunTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FFirstPersonGunTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	AWeaponSystem_Team7Character* PlayerCharacter = Cast<AWeaponSystem_Team7Character>(UGameplayStatics::GetPlayerCharacter(world, 0));
	TestNotNull("FirstPersonGun is set correctly", PlayerCharacter->FP_Gun);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFirstPersonCameraComponentTest, "UnitTests.FirstPersonCameraComponentTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FFirstPersonCameraComponentTest::RunTest(const FString& Parameters)
{
	AutomationOpenMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange"));
	UWorld* world = GetTestWorld();
	AWeaponSystem_Team7Character* PlayerCharacter = Cast<AWeaponSystem_Team7Character>(UGameplayStatics::GetPlayerCharacter(world, 0));
	TestNotNull("FirstPersonCameraComponent is set correctly", PlayerCharacter->FirstPersonCameraComponent);
	return true;
}