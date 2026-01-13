#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SLeafWidget.h"
#include "ScopedTransaction.h"
#include "Paper2DPlusCharacterDataAsset.h"

class UPaperSprite;
class SVerticalBox;
class SHorizontalBox;
class FCharacterDataAssetEditorToolkit;
class SDimensionManagementPanel;

/** Tool modes for the hitbox editor */
enum class EHitboxEditorTool : uint8
{
	Draw,		// Draw new hitboxes
	Edit,		// Select, move, resize hitboxes
	Socket		// Place sockets
};

/** Selection type */
enum class EHitboxSelectionType : uint8
{
	None,
	Hitbox,
	Socket
};

/** Resize handle positions */
enum class EResizeHandle : uint8
{
	None,
	TopLeft, Top, TopRight,
	Left, Right,
	BottomLeft, Bottom, BottomRight
};

/** Drag mode for mouse operations */
enum class EHitboxDragMode : uint8
{
	None,
	Creating,		// Drawing a new hitbox
	Moving,			// Moving selected hitbox/socket
	Resizing		// Resizing selected hitbox
};

/**
 * Interactive canvas widget for drawing and editing hitboxes.
 * Handles mouse input for drawing, selecting, moving, and resizing.
 */
class SCharacterDataEditorCanvas : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SCharacterDataEditorCanvas) {}
		SLATE_ARGUMENT(TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>, Asset)
		SLATE_ATTRIBUTE(int32, SelectedAnimationIndex)
		SLATE_ATTRIBUTE(int32, SelectedFrameIndex)
		SLATE_ATTRIBUTE(EHitboxEditorTool, CurrentTool)
		SLATE_ATTRIBUTE(bool, ShowGrid)
		SLATE_ATTRIBUTE(float, Zoom)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SWidget interface
	virtual FVector2D ComputeDesiredSize(float) const override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual bool SupportsKeyboardFocus() const override { return true; }
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

	// Selection
	DECLARE_DELEGATE_TwoParams(FOnSelectionChanged, EHitboxSelectionType, int32);
	FOnSelectionChanged OnSelectionChanged;

	DECLARE_DELEGATE(FOnHitboxDataModified);
	FOnHitboxDataModified OnHitboxDataModified;

	DECLARE_DELEGATE(FOnRequestUndo);
	FOnRequestUndo OnRequestUndo;

	DECLARE_DELEGATE(FOnEndTransaction);
	FOnEndTransaction OnEndTransaction;

	// External selection control
	void SetSelection(EHitboxSelectionType Type, int32 Index);
	void ClearSelection();
	EHitboxSelectionType GetSelectionType() const { return SelectionType; }
	int32 GetSelectedIndex() const { return SelectedIndex; }

	// Nudge selection by delta
	void NudgeSelection(int32 DeltaX, int32 DeltaY);

	// Delete current selection
	void DeleteSelection();

private:
	TWeakObjectPtr<UPaper2DPlusCharacterDataAsset> Asset;
	TAttribute<int32> SelectedAnimationIndex;
	TAttribute<int32> SelectedFrameIndex;
	TAttribute<EHitboxEditorTool> CurrentTool;
	TAttribute<bool> ShowGrid;
	TAttribute<float> Zoom;

	// Selection state
	EHitboxSelectionType SelectionType = EHitboxSelectionType::None;
	int32 SelectedIndex = -1;

	// Drag state
	EHitboxDragMode DragMode = EHitboxDragMode::None;
	FVector2D DragStart;
	FVector2D DragCurrent;
	EResizeHandle ActiveHandle = EResizeHandle::None;

	// For creating new hitbox
	FIntRect CreatingRect;

	// Helpers
	FLinearColor GetHitboxColor(EHitboxType Type) const;
	const FFrameHitboxData* GetCurrentFrame() const;
	FFrameHitboxData* GetCurrentFrameMutable() const;
	const FAnimationHitboxData* GetCurrentAnimation() const;
	bool GetCurrentSpriteInfo(UPaperSprite*& OutSprite, FVector2D& OutDimensions) const;

	// Coordinate conversion
	FVector2D ScreenToCanvas(const FGeometry& Geom, const FVector2D& ScreenPos) const;
	FVector2D CanvasToScreen(const FGeometry& Geom, const FVector2D& CanvasPos) const;
	FVector2D GetCanvasOffset(const FGeometry& Geom) const;
	float GetEffectiveZoom(const FGeometry& Geom) const;
	FVector2D GetSpriteDimensions() const;

	// Hit testing
	int32 HitTestHitbox(const FVector2D& CanvasPos) const;
	int32 HitTestSocket(const FVector2D& CanvasPos) const;
	EResizeHandle HitTestHandle(const FVector2D& CanvasPos, const FHitboxData& Hitbox) const;

	// Drawing helpers
	void DrawGrid(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const;
	void DrawHitbox(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FHitboxData& HB, bool bSelected) const;
	void DrawSocket(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FSocketData& Sock, bool bSelected) const;
	void DrawResizeHandles(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FHitboxData& HB) const;
	void DrawCreatingRect(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const;

	// Snap to grid
	int32 SnapToGrid(int32 Value) const;
	static constexpr int32 GridSize = 16;
	static constexpr float HandleSize = 8.0f;
	static constexpr float SocketHitRadius = 10.0f;
};

/**
 * Main editor widget for Paper2DPlusCharacterDataAsset.
 * Contains toolbar, canvas, animation/frame lists, and properties panel.
 */
class SCharacterDataAssetEditor : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCharacterDataAssetEditor) {}
		SLATE_ARGUMENT(UPaper2DPlusCharacterDataAsset*, Asset)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// Keyboard handling
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	TWeakObjectPtr<UPaper2DPlusCharacterDataAsset> Asset;

	// Selection state
	int32 SelectedAnimationIndex = 0;
	int32 SelectedFrameIndex = 0;
	EHitboxEditorTool CurrentTool = EHitboxEditorTool::Draw;
	bool bShowGrid = false;
	float ZoomLevel = 1.0f;

	// Active transaction for undo support
	TUniquePtr<FScopedTransaction> ActiveTransaction;

	// Widget references
	TSharedPtr<SVerticalBox> AnimationListBox;
	TSharedPtr<SVerticalBox> FrameListBox;
	TSharedPtr<SVerticalBox> HitboxListBox;
	TSharedPtr<SVerticalBox> PropertiesBox;
	TSharedPtr<SCharacterDataEditorCanvas> EditorCanvas;
	TSharedPtr<SDimensionManagementPanel> DimensionPanel;

	// Dimension panel expansion state
	bool bDimensionPanelExpanded = false;

	// UI Builders
	TSharedRef<SWidget> BuildToolbar();
	TSharedRef<SWidget> BuildToolPanel();
	TSharedRef<SWidget> BuildAnimationList();
	TSharedRef<SWidget> BuildFrameList();
	TSharedRef<SWidget> BuildCanvasArea();
	TSharedRef<SWidget> BuildHitboxList();
	TSharedRef<SWidget> BuildPropertiesPanel();
	TSharedRef<SWidget> BuildCopyOperationsPanel();
	TSharedRef<SWidget> BuildDimensionManagementSection();

	// Refresh functions
	void RefreshAnimationList();
	void RefreshFrameList();
	void RefreshHitboxList();
	void RefreshPropertiesPanel();
	void RefreshAll();

	// Event handlers
	void OnAnimationSelected(int32 Index);
	void OnFrameSelected(int32 Index);
	void OnToolSelected(EHitboxEditorTool Tool);
	void OnSelectionChanged(EHitboxSelectionType Type, int32 Index);
	void OnHitboxDataModified();
	void OnImportJsonClicked();
	void OnReimportClicked();
	void OnZoomChanged(float NewZoom);

	// Frame navigation
	void OnPrevFrameClicked();
	void OnNextFrameClicked();

	// Copy operations
	void OnCopyFromPrevious();
	void OnPropagateAllToGroup();
	void OnPropagateSelectedToGroup();
	void OnClearCurrentFrame();

	// Undo support
	void BeginTransaction(const FText& Description);
	void EndTransaction();

	// Add new hitbox/socket
	void AddNewHitbox();
	void AddNewSocket();
	void DeleteSelected();

	// Animation management
	void AddNewAnimation();
	void RemoveSelectedAnimation();

	// Frame management
	void AddNewFrame();
	void RemoveSelectedFrame();

	// Helpers
	const FFrameHitboxData* GetCurrentFrame() const;
	FFrameHitboxData* GetCurrentFrameMutable();
	const FAnimationHitboxData* GetCurrentAnimation() const;
	FAnimationHitboxData* GetCurrentAnimationMutable();
	int32 GetCurrentFrameCount() const;
};

/**
 * Asset Editor Toolkit for Paper2DPlusCharacterDataAsset.
 * Provides a dockable, tabbed editor within the Unreal Editor.
 */
class FCharacterDataAssetEditorToolkit : public FAssetEditorToolkit
{
public:
	virtual ~FCharacterDataAssetEditorToolkit();

	void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UPaper2DPlusCharacterDataAsset* InAsset);

	// FAssetEditorToolkit interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	static void OpenEditor(UPaper2DPlusCharacterDataAsset* Asset);

private:
	UPaper2DPlusCharacterDataAsset* EditedAsset = nullptr;
	static const FName CharacterDataEditorTabId;
	TSharedRef<SDockTab> SpawnEditorTab(const FSpawnTabArgs& Args);
};
