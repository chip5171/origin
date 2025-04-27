// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class ULMAWeaponComponent;
class ALMABaseWeapon;
class UAnimMontage;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALMADefaultCharacter();


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAWeaponComponent* WeaponComponent;

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Sprint");
	bool IsSprint = false;

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	float GetStamina() const { return Stamina; }
	
	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }  

	UFUNCTION()
	bool GetIsSprint() const { return IsSprint; }

private:
	float YRotation = -75.0f;
	float ArmLength = 1400.0f;
	float MinArmLength = 300.0f;
	float FOV = 55.0f;
	float ZoomSpeed = 100.0f;

	float Stamina = 100.0f;
	float DeltaStamina = 2.0f;
	
	void MoveForward(float Value);
	void MoveRight(float Value);

	void ZoomCamera(float Value);
	
	void SprintOn();
	void SprintOff();
	void IncreaseStamina();
	void DecreaseStamina();
	void OnStaminaChanged(float Value);
	
	void OnDeath();
	void OnHealthChanged(float NewHealth);
	void RotationPlayerOnCursor();
	//void OnReload();
	
};
