#include "GameTest.h"
#include "AutoTest.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine.h"
#include "EngineUtils.h"
#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNullTest, "UnitTests.NullTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FNullTest::RunTest(const FString& Parameters)
{
	/*FAutomationEditorCommonUtils::LoadMap(TEXT("/Game/FirstPersonCPP/Maps/Level_ShootingRange.Level_ShootingRange"));
	UObject* EditorCylinderMesh = (UStaticMesh*)StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Engine/EditorMeshes/EditorCylinder.EditorCylinder"), NULL, LOAD_None, NULL);*/
	TestNull("Null is null", nullptr);
	//TestNotNull("Mesh is valid", EditorCylinderMesh);
	//TestNotNull("I can instantiate meshes!", FActorFactoryAssetProxy::AddActorForAsset(EditorCylinderMesh));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FWorldTest, "UnitTests.WorldTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FWorldTest::RunTest(const FString& Parameters)
{
	TestNotNull("World exists", GWorld.GetReference());
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