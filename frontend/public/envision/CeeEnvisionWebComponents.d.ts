// HOOPS Envision for Web, version 6.1.0+b2990ab8
// Copyright (C) 2025, Ceetron AS, https://techsoft3d.com/
// Use of this file requires a usage and/or distribution license from Ceetron AS or Tech Soft 3D Inc.
// The contents of this file may not be copied or duplicated in any form, in whole or in part, 
// without the prior written permission of Ceetron AS or Tech Soft 3D Inc.

// Type definitions for HOOPS Envision for Web, version: 6.1.0-b2990ab8 

// Make cee available as a global for non-module code.
export as namespace cee;

/**
 * Controls usage of ambient occlusion in a View.
 *
 * You can access the ambient occlusion object though the {@link View.ambientOcclusion} property.
 */
export class AmbientOcclusion {
    /**
     * Enable or disable ambient occlusion
     */
    get enable(): boolean;
    set enable(enable: boolean);
    /**
     * Specify the screen proportional radius of the ambient occlusion effect
    */
    get screenProportionalRadius(): number;
    set screenProportionalRadius(radius: number);
}

/** @module cee */ /** */
/**
 * Background configuration
 *
 * The class defines the view background settings. The background can either be single colored or
 * be a gradient between a top and a bottom color.
 * Image backgrounds are also supported, in which case the image will be rendered on top of the
 * specified background color.
 *
 * You can access the background object from the view with the {@link View.background} property.
 */
export class Background {
    /**
     * The top color of the background.
     *
     * If background is single color, the topColor and bottomColor properties are equal
    */
    get topColor(): Color4;
    /**
     * The bottom color of the background.
     *
     * If background is single color, the topColor and bottomColor properties are equal
    */
    get bottomColor(): Color4;
    /**
     * If image background is in use it returns the image uses as a background.
    */
    get image(): Texture | null;
    /**
     * Sets the background color to the given color (single color)
     *
     * The background of the view will be cleared with the given color, and no graded background will
     * be rendered. This is the default mode.
    */
    setSingleColor(color: Color4Like): void;
    /**
     * Sets the background color to a gradient defined by a top color and a bottom color
    */
    setTopAndBottomColor(topColor: Color4Like, bottomColor: Color4Like): void;
    /**
     * Use the given image as the background of the view
     *
     * Specify null to clear any previously specified background image.
     */
    setImage(texture: Texture | null): void;
}

/** @module cee */ /** */
/**
 * An axis-oriented bounding box storing the extent of an object.
 *
 * All vertices of the object that the bounding box has been computed for will be within the
 * box defined by the min and max corners.
 *
 * Note that this class is immutable.
 */
export class BoundingBox {
    /**
     * The minimum values for x, y and z across all vertices in the object.
     */
    readonly minimum: Vec3;
    /**
     * The maximum values for x, y and z across all vertices in the object.
     */
    readonly maximum: Vec3;
    /**
     *  Creates a bounding box with the given min and max corners.
     */
    constructor(minimum: Vec3Like, maximum: Vec3Like);
    /**
     * Creates an invalid bounding box where maximum < minimum for x, y and z
     */
    static createInvalid(): BoundingBox;
    /**
     *  Returns true if the bounding box is valid, i.e. if minimum < maximum for x, y and z.
     */
    isValid(): boolean;
    /**
     *  Returns the center of the bounding box
     */
    getCenter(): Vec3;
    /**
     * Returns the extent for each component (x,y,z) of the bounding box (maximum - minimum).
     */
    getExtent(): Vec3;
}

/** @module cee */ /** */
/**
 *  The projection type of the camera
 */
export enum ProjectionType {
    /**
     * Perspective projection
     */
    PERSPECTIVE = 0,
    /**
     * Orthographic (parallel) projection
     */
    ORTHO = 1
}
/**
 * Specifies a camera configuration
 */
export interface CameraConfig {
    eye: Vec3Like;
    direction: Vec3Like;
    up: Vec3Like;
    fieldOfViewYDeg?: number;
    frontPlaneFrustumHeight?: number;
}
/**
 * A handler that is invoked each time the camera view changes
 */
export interface CameraViewChangeHandler {
    (): void;
}
/**
 * Camera settings (view point and projection) for a View.
 *
 * Use this class to get a View's current eye point, view direction and up vector.
 *
 * Setup the camera by providing the eye, view reference point (center) and up vector to {@link setFromLookAt}.
 *
 * You can also use this class to setup the projection and control the front and back clipping planes.
 *
 * You can access a View's camera with the {@link View.camera} property.
 */
export class Camera {
    /**
     *
     */
    private constructor();
    /**
     * Returns the total field of view in the Y direction in degrees.
     *
     * Returns undefined if parallel (orthographic) projection
     */
    get fieldOfViewYDeg(): number | undefined;
    /**
     * Get height of the view frustum in the front plane in world coordinates.
     */
    get frontPlaneFrustumHeight(): number;
    /**
     * Returns the near clipping plane
     */
    get nearPlane(): number;
    /**
     * Returns the far clipping plane
     */
    get farPlane(): number;
    /**
     * Returns the viewport of the camera
     */
    get viewport(): {
        x: number;
        y: number;
        width: number;
        height: number;
    };
    /**
     * Returns the current projection type (perspective/ortho)
     */
    get projectionType(): ProjectionType;
    /**
     * Returns the current view matrix
     */
    get viewMatrix(): Mat4;
    /**
     * Sets the view matrix of the camera.
     */
    setViewMatrix(viewMatrix: Mat4): void;
    /**
     * Sets up a perspective projection.
     *
     * The fieldOfViewYDeg parameter is the total field of view angle (in degrees) in the Y direction.
     * Works similar to gluPerspective().
     */
    setProjectionAsPerspective(fieldOfViewYDeg: number, nearPlane: number, farPlane: number): void;
    /**
     * Sets up an orthographic (parallel) projection.
     *
     * The height parameter is the height of the frustum. A good default is the length of the extent
     * of the current bounding box.
     */
    setProjectionAsOrtho(height: number, nearPlane: number, farPlane: number): void;
    /**
     * Sets the front and back clipping planes close to the given bounding box
     */
    setClipPlanesFromBoundingBox(boundingBox: BoundingBox, minNearPlaneDistance: number): void;
    /**
     * Returns the camera's position (eye point)
     */
    getPosition(): Vec3;
    /**
     * Returns camera's forward direction vector. The returned vector is normalized.
     */
    getDirection(): Vec3;
    /**
     * Returns the camera's up vector. The returned vector is normalized.
     */
    getUp(): Vec3;
    /**
     * Sets the viewpoint from the eye point position, direction and up vectors.
     */
    setViewpoint(eye: Vec3Like, direction: Vec3Like, up: Vec3Like): void;
    /**
     * Sets the view matrix from the standard OpenGL 'lookat' (eye, center, vup) specification.
     *
     * View direction will be (center - eye). Center is not stored in this class.
     */
    setFromLookAt(eye: Vec3Like, center: Vec3Like, up: Vec3Like): void;
    /**
     * Helper that applies a camera config to the camera
     */
    applyCameraConfig(config: CameraConfig, allowChangeOfProjectionType: boolean): void;
    /**
     * Sets up the view to contain the passed bounding box, with the camera looking from the given
     * direction (dir) and with the given up vector (up).
     *
     * The passed boundingBox should be the bounding box of the object/model you would like to fit
     * the view to.
     *
     * The relativeDistance parameter specifies the distance from the camera to the
     * center of the bounding box.
     *
     * Note: This only works for perspective projection. For orthographic (parallel) projections,
     * use the fitViewOrtho method.
     */
    fitView(boundingBox: BoundingBox, dir: Vec3Like, up: Vec3Like, coverageFactor?: number): void;
    /**
     * Zoom in/out so the given bounding box will fill the view.
     *
     * This is done without changing the current camera position. It works for both for PERSPECTIVE and
     * ORTHO projection types.
     *
     * Note: Works best with ZOOM navigation. Combining zoom (changing FOV) and walk navigation can give
     * distorted views.
     */
    zoomToBoundingBox(boundingBox: BoundingBox): void;
    /**
     * Sets up the view to contain the passed bounding box, with the camera looking from the given
     * direction 'dir', at the give distance 'eyeDist' and with the given up vector 'up'.
     *
     * We recommend to set the 'eyeDist' to boundingBox.radius()*2.0
     *
     * The passed boundingBox should be the bounding box of the object/model you would like to fit
     * the view to.
     *
     * Note: This only works for orthographic (parallel) projection. For perspective projections,
     * use the fitView method.
     */
    fitViewOrtho(boundingBox: BoundingBox, eyeDist: number, dir: Vec3Like, up: Vec3Like, coverageFactor?: number): void;
    /**
     * Calculate the camera position required to fit the given bounding box in the view when the camera is orientated with the
     * given direction and up vectors.
     */
    computeFitViewEyePosition(boundingBox: BoundingBox, dir: Vec3, up: Vec3, coverageFactor?: number): Vec3;
    /**
     * Enables the auto clipping feature and sets a minimum near distance
     */
    enableAutoClipMinimumNearDistance(minNearDistance: number): void;
    /**
     * Enables the auto clipping feature and sets a fixed near distance
     */
    enableAutoClipFixedNearDistance(fixedNearDistance: number): void;
    /**
     * Disables the auto clipping feature
     */
    disableAutoClip(): void;
    /**
     * Maps world (3d) coordinates to window coordinates
     *
     * Returns null if the specified point cannot be projected.
     *
     * The returned window coordinates 'out' are in WebGL/OpenGL style coordinates, which means a right handed
     * coordinate system with the origin in the lower left corner of the window.
     *
     * OpenGL like project.
     */
    project(point: Vec3Like): Vec3 | null;
    /**
     * Maps window coordinates to world (3d) coordinates
     *
     * Returns null if the specified coordinate cannot be unprojected.
     *
     * The input (window) coordinates 'coord' must be specified in WebGL/OpenGL style coordinates, which means
     * a right handed coordinate system with the origin in the lower left corner of the window.
     *
     * OpenGL like unproject.
     *
     * Use {@link Viewer.oglWinPosFromClientCoord} to convert client coordinates into WebGL style coordinates
     */
    unproject(coord: Vec3Like): Vec3 | null;
    /**
     * Resets the camera to its initial state as it appeared upon creation of its containing view
     */
    resetCamera(): void;
    /**
     * Sets a handler to be invoked each time the camera view changes
     * @param handler The handler to invoke on change
     * @param waitForIdle If true, the handler will only be invoked after any ongoing mouse operations or camera animations have completed.
     *                    Note that setting this to false will result in a large number of handler invocations, while setting this to true
     *                    and then starting a never-ending camera animation will result in no invocations.
     */
    setViewChangeHandler(handler: CameraViewChangeHandler, waitForIdle: boolean): void;
}

/** @module cee */ /** */
/**
 * Interface for camera animations that can be used with a Viewer
 */
export interface CameraAnimation {
    /**
     * Called to update the camera. Return true if camera changed and a redraw should be triggered
     */
    updateCamera(highResTimestamp_ms: number, isResumingAfterPause: boolean): boolean;
    /**
     * Query if the camera animation is finished. Return true to signal that the camera animation is
     * finished and that the Viewer should release the camera animation object.
     */
    isAnimationDone(): boolean;
    /**
     * Whether this camera animation should be aborted if user navigation/interaction is detected
     */
    isAbortableByUserNavigation(): boolean;
}

/** @module cee */ /** */
/**
 * Camera animation for spinning the model around the given axis and point.
 *
 * The camera will keep its distance to the given rotation point and the current up vector.
 * The animation will orbit the model giving the illusion that the model is spinning around
 * the prescribed axis.
 *
 * The speed of the camera movement can be controlled with setting the duration of a full rotation.
 */
export class CameraAnimationSpinModel implements CameraAnimation {
    /**
     * Constructor with camera that is to be manipulated
     */
    constructor(camera: Camera);
    /**
     * Set rotation point and rotation axis
     */
    setRotationPointAndAxis(rotPoint: Vec3Like, rotAxis: Vec3Like): void;
    /**
     * Set the duration, in seconds, of one complete 360 degree rotation
     */
    setFullRotationDuration(durationInSeconds: number): void;
    /**
     * Set the target camera animation speed in frames per second (max FPS)
     */
    setTargetFrameRate(framesPerSecond: number): void;
    /**
     * Set the duration, in seconds, of one complete 360 degree rotation
     */
    setIsAbortableByUserNavigation(isAbortable: boolean): void;
    /**
     * Updates the camera
     */
    updateCamera(highResTimestamp_ms: number, isResumingAfterPause: boolean): boolean;
    /**
     * Query if the camera animation is finished.
     */
    isAnimationDone(): boolean;
    /**
     * Whether this camera animation should be aborted if user navigation/interaction is detected
     */
    isAbortableByUserNavigation(): boolean;
}

/** @module cee */ /** */
export enum ClippingCriteria {
    /** Object/fragment will be clipped if it is behind at least one of the planes in the group */
    BehindOneOrMorePlanes = 0,
    /** Object/fragment will only be clipped if it is behind all the planes in the group */
    BehindAllPlanes = 1
}
/**
 * Manages general clipping planes in a View.
 *
 * Anything behind (on the opposite side of the plane normal) the given planes is hidden.
 *
 * Note: The ug.RemoteModel has clipping support connect to cutting planes. These are handled separately,
 *       and the clipping planes for cutting planes will not show up here.
 *
 * **Bounded clipping planes**
 *
 * EnvisionWeb supports bounded clipping planes. This allows for cutting out parts of the model in many
 * different ways. By default a clipping plane will clip an object/fragment if it is
 * behind the specified plane (on the opposite side of the plane normal).
 * Bounded clipping planes can be created by assigning all the wanted planes the same group ID when
 * adding them, and then setting the clipping criteria for the group to ClippingCriteria.BehindAllPlanes.
 *
 * You can access the clipping object with the {@link View.clipping} property.
 */
export class Clipping {
    /**
     *
    */
    private constructor();
    /**
     * The number of clipping planes in the view
     */
    get planeCount(): number;
    /**
     * Return the Plane at the given index
     */
    getPlane(index: number): Plane;
    /**
     * Returns a readonly array of all the planes in the view
     */
    getPlaneArray(): ReadonlyArray<Plane>;
    /**
     * Return the group id of the plane at the specified  index
     */
    getGroupId(index: number): number;
    /**
     * Adds a clipping plane to the view.
     *
     * By default the plane clips anything behind the plane (on the opposite side of the plane normal).
     * This can be changed by specifying the clipping criteria for the plane group to which this
     * plane belongs using {@link Clipping.setGroupClippingCriteria}
     */
    addPlane(plane: Plane, groupId?: number): void;
    /**
     * Sets a clipping plane at the given index.
     *
     * By default the plane clips anything behind the plane (on the opposite side of the plane normal).
     */
    setPlane(index: number, plane: Plane): void;
    /**
     * Remove the clipping plane at the given index
     */
    removePlane(index: number): void;
    /**
     * Removes all clipping planes in the view
     *
     * Also clears any plane groups and clipping criteria that has been specified
     */
    removeAllPlanes(): void;
    /**
     * Sets clipping criteria for the specified group of planes
     */
    setGroupClippingCriteria(groupId: number, groupClippingCriteria: ClippingCriteria): void;
}

/** @module cee */ /** */
/**
 * The CloudSession's responsibility is to manage the {@link Viewer Viewers} and the main event loop of
 * EnvisionWeb ({@link handleAnimationFrameCallback}).
 *
 * All EnvisionWeb applications need a CloudSession object. There is only need for one, even in apps
 * with multiple viewers, views, models and remote servers.
 */
export class CloudSession {
    /**
     * Constructor
     */
    constructor();
    /**
     * Returns the version of HOOPS Envision for Web
     *
     * Format: Major.Minor.Patch-Build. E.g. '1.2.0+34145A' or '1.2.0-rc1++38C14A
     */
    get version(): string;
    /**
     * Returns the date and time this version of EnvisionWeb was built
     */
    get buildDateTimeString(): string;
    /**
     * Returns the number of viewers in the client application.
     */
    get viewerCount(): number;
    /**
     * Returns a read only array with all viewers in the session
     */
    getViewerArray(): ReadonlyArray<Viewer>;
    /**
     * Adds a new Viewer to the session.
     *
     * The Viewer is tied to a HTML Canvas element, and the provided canvas must be capable of rendering WebGL.
     * Returns null if the canvas is not capable of rendering WebGL or if WebGL resources are exhausted.
     *
     * A Viewer can have many {@link View Views}, and all the Views within a Viewer can share WebGL resources.
     * So, to show the same Model in two Views, using one Viewer with two Views is more efficient
     * than using two Viewers with one View each.
     *
     * A client application can contain many Viewers, but each Viewer must be linked to single unique Canvas.
     */
    addViewer(canvas: HTMLCanvasElement, viewerOptions?: ViewerOptions): Viewer | null;
    /**
     * Returns the viewer with the given index.
     *
     * The index must be zero based and between 0 and viewerCount - 1
     */
    getViewerAt(index: number): Viewer;
    /**
     * Deletes the viewer at the given index.
     *
     * The index must be zero based and between 0 and viewerCount - 1
     */
    deleteViewerAt(index: number): void;
    /**
     * Deletes all viewers from the app.
     */
    deleteAllViewers(): void;
    /**
     * Destroys the session object. This will delete all the viewers.
     */
    destroySession(): void;
    /**
     * Mandatory update method for the HOOPS Envision Client.
     *
     * This method must be called from a requestAnimationFrame() for animations to run and
     * server communication to work as expected.
     *
     * The standard code for doing this is:
     * ```javascript
     * // Setup timer to keep the session viewer up-to-date
     * function myAnimationFrameCallback(highResTimestamp) {
     *     mySession.handleAnimationFrameCallback(highResTimestamp);
     *     requestAnimationFrame(myAnimationFrameCallback);
     * }
     *
     * requestAnimationFrame(myAnimationFrameCallback);
     * ```
     */
    handleAnimationFrameCallback(highResTimestamp_ms: number): boolean;
    /**
     * Manually add a model to the set of models that need background processing
     */
    addModelToProcessingSet(model: ProcessableModel): void;
    /**
     * Remove a model that was previously added manually to the processing set
     */
    removeModelFromProcessingSet(model: ProcessableModel): void;
}

/** @module cee */ /** */
/**
 * Interface describing an object with r,g,b properties.
 */
export interface Color3Like {
    /** The red component of the color. Range: 0..1  */
    readonly r: number;
    /** The green component of the color. Range: 0..1  */
    readonly g: number;
    /** The blue component of the color. Range: 0..1  */
    readonly b: number;
}
/**
 * An immutable three component (RGB) color.
 *
 * The color components (r,g,b) are in the range 0..1.
 *
 * Note that this class is immutable.
 */
export class Color3 {
    /**
     * The red component of the color. Range: 0..1
     */
    readonly r: number;
    /**
     * The green component of the color. Range: 0..1
     */
    readonly g: number;
    /**
     * The blue component of the color. Range: 0..1
     */
    readonly b: number;
    /**
     * Creates a color object.
     */
    constructor(r: number, g: number, b: number);
    /**
     * Returns true if the colors are equal.
     */
    equals(other: Color3Like): boolean;
    /**
     * Creates a Color3 instance from any object with r,g,b properties
     */
    static from(color: Color3Like): Color3;
    /**
     * Creates a Color3 instance from the r,g,b properties of the given RGBA color, ignoring the alpha channel
     */
    static fromColor4(color: Color4Like): Color3;
    /**
     * Creates a new Color3 instance from the first 3 elements of the given array.
     */
    static fromArray(arr: ArrayLike<number>): Color3;
}

/** @module cee */ /** */
/**
 * Interface describing an object with r,g,b,a properties.
 */
export interface Color4Like {
    /** The red component of the color. Range: 0..1  */
    readonly r: number;
    /** The green component of the color. Range: 0..1  */
    readonly g: number;
    /** The blue component of the color. Range: 0..1  */
    readonly b: number;
    /** The alpha component of the color. Range: 0..1  */
    readonly a: number;
}
/**
 * An immutable four component (RGBA) color.
 *
 * The color components (r,g,b,a) are in the range 0..1
 *
 * Note that this class is immutable.
 */
export class Color4 {
    /**
     * The red component of the color. Range: 0..1
     */
    readonly r: number;
    /**
     * The green component of the color. Range: 0..1
     */
    readonly g: number;
    /**
     * The blue component of the color. Range: 0..1
     */
    readonly b: number;
    /**
     * The alpha component of the color. Range: 0..1, where 1 is fully opaque and 0 is fully transparent (invisible)
     */
    readonly a: number;
    /**
     * Creates a color object
     */
    constructor(r: number, g: number, b: number, a: number);
    /**
     * Returns true if the colors are equal
     */
    equals(other: Color4Like): boolean;
    /**
     * Creates a Color4 instance from any object with r,g,b,a properties
     */
    static from(color: Color4Like): Color4;
}

/** @module cee */ /** */
/**
 * Provides a collection of color mapping schemes used for data visualization,
 * thermal scalar displays, and various gradient representations.
 *
 * This enum defines a range of color tables, each useful for mapping numeric
 * values to specific color gradients. The selection covers general-purpose spectrums,
 * thermal mappings, and specialized gradients for particular visual effects.
 *
 * - RAINBOW: Maps values using a rainbow spectrum starting from blue and progressing to red.
 * - RAINBOW_REVERSE: Inverse of the RAINBOW mapping; begins with red and transitions to blue.
 * - BLACK_WHITE: A grayscale mapping from black to white.
 * - BLUE_RED: Interpolates colors in a gradient from blue to red.
 * - BLUE_GREEN: Gradually transitions colors from blue to green.
 * - YELLOW_RED: Provides a gradient that shifts from yellow to red.
 * - GREEN_YELLOW_RED: Starts at green, passes through yellow, and ends at red.
 * - RED_YELLOW: Maps from red to yellow.
 * - THERMAL_1: A variant of a colormap optimized for representing thermal data.
 * - THERMAL_2: An alternative thermal colormap for enhanced scalar visualizations.
 * - THERMAL_3: Another thermal variant, offering a slightly different gradient for thermal data.
 * - METAL_CASTING: Tailored for visualizing processes such as metal casting.
 * - VIRIDIS: A perceptually uniform colormap transitioning from purple to yellow.
 * - TURBO: A vibrant, rainbow-based colormap suitable for detailed thermal displays.
 * - COOL_TO_WARM: Represents a gradient transitioning from cool blue tones to warm red hues.
 * - NORMAL: Alias for RAINBOW; maintained for backward compatibility (considered deprecated).
 */
export enum ColorTable {
    RAINBOW = 0,
    RAINBOW_REVERSE = 1,
    BLACK_WHITE = 2,
    BLUE_RED = 3,
    BLUE_GREEN = 4,
    YELLOW_RED = 5,
    GREEN_YELLOW_RED = 6,
    RED_YELLOW = 7,
    THERMAL_1 = 8,
    THERMAL_2 = 9,
    THERMAL_3 = 10,
    METAL_CASTING = 11,
    VIRIDIS = 12,
    TURBO = 13,
    COOL_TO_WARM = 14,
    NORMAL = 0
}
/**
 *
 */
export class ColorTableFactory {
    /**
     * Returns an array of Color3 created from the given color scheme.
     *
     * The returned array will have colorCount number of values
     */
    static color3TableArray(colorTable: ColorTable, colorCount: number): Color3Like[];
    /**
     * Returns an array of Color4 created from the given color scheme.
     *
     * The returned array will have colorCount number of values. All alpha values will be set to 1.
     */
    static color4TableArray(colorTable: ColorTable, colorCount: number): Color4Like[];
    /**
     * Interpolate a graded color table with the given number of colors (targetColorCount) based on
     * the input colors (colorArray).
     *
     * This is useful for creating gradient/continuous style color maps based on two or more colors.
     */
    static interpolateColorArray(colorArray: Color3Like[], targetColorCount: number): Color3Like[];
    /**
     * Interpolate a graded color table with the given number of colors (targetColorCount) based on
     * the input colors (colorArray).
     *
     * This is useful for creating gradient/continuous style color maps based on two or more colors.
     */
    static interpolateColor4Array(colorArray: Color4Like[], targetColorCount: number): Color4Like[];
    /**
     * Returns an array with colors matching the part colors in the Envision and the cee.ug component.
     */
    static partColorArray(colorCount: number): Color3Like[];
}

export enum EventType {
    onMouseDown = "onMouseDown",
    onMouseUp = "onMouseUp",
    onClick = "onClick",
    onDblClick = "onDblClick",
    onMouseMove = "onMouseMove",
    onTouchStart = "onTouchStart",
    onTouchMove = "onTouchMove",
    onTouchEnd = "onTouchEnd",
    onPointerDown = "onPointerDown",
    onPointerUp = "onPointerUp",
    onPointerMove = "onPointerMove",
    onWheel = "onWheel",
    onKeyDown = "onKeyDown",
    onKeyUp = "onKeyUp"
}

/** @module cee */ /** */
/**
 * Eye lift modes
 */
export enum EyeLift {
    /**
     * No eye lift is used (default)
     */
    OFF = 0,
    /**
     * Eye lift towards with factor 1.0
     */
    FACTOR_1 = 1,
    /**
     * Eye lift towards with factor 0.1
     */
    FACTOR_0_1 = 2,
    /**
     * Eye lift towards with factor 0.01
     */
    FACTOR_0_01 = 3
}

/**
 * Interface for callback that is called when a code assert fails in the internal HOOPS Envision Web code
 *
 * error will contain the error assert message and the call stack.
 *
 * You can register to receive a callback with the {@link setAssertFailedHandler} function.
 */
export interface AssertFailedHandler {
    (error: Error, condition: any): never;
}
/**
 * Set a custom code assert failed handler.
 *
 * If specified, any failing assert conditions internally in the HOOPS Envision Web code will trigger this callback.
 *
 * If not specified, the failed assert will be logged and then an exception will be thrown (potentially stopping the app).
 */
export function setAssertFailedHandler(handler: AssertFailedHandler): void;
/**
 * The logger used in HOOPS Envision for Web (EnvisionWeb)
 *
 * Static class for controlling the log output from EnvisionWeb, and for logging within the client app.
 *
 * Use the {@link enableInfo} function to turn on/off info logging from EnvisionWeb.
 *
 * Use the {@link enableDebug} function to turn on/off debug logging from EnvisionWeb.
 *
 * These should only be used for debugging and should be disabled in a production environment.
 */
export class Logger {
    /**
     * Logs an error message.
     */
    static error: (...args: any[]) => void;
    /**
     * Logs a warning message.
     */
    static warn: (...args: any[]) => void;
    /**
     * Logs an info message. Will be shown if info messages are enabled.
     */
    static info: (_msg: string) => void;
    /**
     * Logs a debug message. Will be shown if debug messages are enabled.
     */
    static debug: (_msg: string) => void;
    /**
     * Enables/disables info log messages.
     *
     * Info log messages contain information about the client and communication with the server.
     */
    static enableInfo(enable?: boolean): void;
    /**
     * Enables/disables debug log messages.
     *
     * Debug log messages contain detailed debug information about the client and communication with the server.
     */
    static enableDebug(enable?: boolean): void;
}

/**
 * An immutable 4x4 matrix
 *
 * Matrices are stored internally as a one dimensional array for performance reasons.
 *
 * The mapping of matrix elements to indices of this internal array is as follows:
 *
 * ```
 *   | m00  m01  m02  m03 |     | 0  4   8  12 |
 *   | m10  m11  m12  m13 |     | 1  5   9  13 |
 *   | m20  m21  m22  m23 |     | 2  6  10  14 |
 *   | m30  m31  m32  m33 |     | 3  7  11  15 |
 * ```
 *
 * This is consistent with the way matrices are represented in WebGL.
 * To exemplify, translation values are stored in elements 12,13,14; see figure below
 *
 * ```
 *   | 1  0  0 Tx |
 *   | 0  1  0 Ty |
 *   | 0  0  1 Tz |
 *   | 0  0  0  1 |
 * ```
 *
 * From the OpenGL red book (page 68)   v' = M*v
 *
 * ```
 *   | X'|   | 1  0  0 Tx |   | X |
 *   | Y'|   | 0  1  0 Ty |   | Y |
 *   | Z'| = | 0  0  1 Tz | * | Z |
 *   | 1 |   | 0  0  0  1 |   | 1 |
 * ```
 *
 * Note that this class is immutable.
 */
export class Mat4 {
    /**
     * Creates the matrix. Default is an identity matrix.
     */
    constructor();
    /**
     * Returns true if the matrix is an identity matrix
     */
    isIdentity(): boolean;
    /**
     * Returns true if the matrices are equal
     */
    equals(other: Mat4): boolean;
    /**
     * Returns this inverse of this matrix.
     *
     * If this matrix is not invertible, returns a zero matrix.
     */
    getInverse(): Mat4;
    /**
     * Returns the value at the given row and column
     */
    getRowCol(row: number, col: number): number;
    /**
     * Returns a reference to the internal array storing the matrix values.
     *
     * The array will be ordered as follows:
     *
     * ```
     *   | m00  m01  m02  m03 |     | 0  4   8  12 |
     *   | m10  m11  m12  m13 |     | 1  5   9  13 |
     *   | m20  m21  m22  m23 |     | 2  6  10  14 |
     *   | m30  m31  m32  m33 |     | 3  7  11  15 |
     * ```
     */
    getAsArray(): ArrayLike<number>;
    /**
     * Multiplies given matrices.
     */
    static multiply(...matrices: Mat4[]): Mat4;
    /**
     * Adds translation to the given matrix M by pre-multiplying it with a matrix containing the given translation tv.
     *
     * This has the effect of performing the multiplication M' = T x M
     */
    static translatePreMultiply(M: Mat4, tv: Vec3Like): Mat4;
    /**
     * Adds translation to the given matrix M by post-multiplying it with a matrix containing the given translation tv.
     *
     * This has the effect of performing the multiplication M' = M x T
     */
    static translatePostMultiply(M: Mat4, tv: Vec3Like): Mat4;
    /**
     * Returns a matrix initialized with the values in the passed array
     *
     * The array must be ordered as follows:
     *
     * ```
     *   | m00  m01  m02  m03 |     | 0  4   8  12 |
     *   | m10  m11  m12  m13 |     | 1  5   9  13 |
     *   | m20  m21  m22  m23 |     | 2  6  10  14 |
     *   | m30  m31  m32  m33 |     | 3  7  11  15 |
     * ```
     */
    static fromArray(array: ArrayLike<number>): Mat4;
    /**
     * Returns a transformation matrix containing only rotation, specified as a rotation around the given axis
     */
    static fromRotation(axis: Vec3Like, angle: number): Mat4;
    /**
     * Returns a rotation matrix that will align the global X, Y and Z axes with the specified axes.
     *
     * Note that at least one axis must be specified and all specified axes must be normalized.
     * If two or three axes are specified, they must be orthogonal to each other.
     *
     * @param xAxis  Orientation of x axis
     * @param yAxis  Orientation of y axis
     * @param zAxis  Orientation of z axis
     */
    static fromCoordSystemAxes(xAxis: Vec3Like, yAxis: Vec3Like, zAxis: Vec3Like): Mat4;
    /**
     * Returns a transformation matrix containing only the given translation
     *
     * Will set m03 to x, m13 to y, and m23 to z, resulting in the following matrix
     *
     * ```
     *   | 1  0  0 Tx |
     *   | 0  1  0 Ty |
     *   | 0  0  1 Tz |
     *   | 0  0  0  1 |
     * ```
     */
    static fromTranslation(trans: Vec3Like): Mat4;
    /**
     * Returns a transformation matrix containing only the given scaling
     *
     * ```
     *   | Sx 0  0  0 |
     *   | 0  Sy 0  0 |
     *   | 0  0  Sz 0 |
     *   | 0  0  0  1 |
     * ```
     */
    static fromScaling(scale: Vec3Like): Mat4;
    /**
     * Returns a transformation matrix containing the given element values
     *
     * ```
     *   | m00  m01  m02  m03 |
     *   | m10  m11  m12  m13 |
     *   | m20  m21  m22  m23 |
     *   | m30  m31  m32  m33 |
     * ```
     */
    static fromElements(m00: number, m01: number, m02: number, m03: number, m10: number, m11: number, m12: number, m13: number, m20: number, m21: number, m22: number, m23: number, m30: number, m31: number, m32: number, m33: number): Mat4;
}

/** @module cee */ /** */
/**
 * Model types.
 */
export enum ModelType {
    Cug = 0,
    Geo = 1,
    Mrk = 2,
    Pt = 3,
    Sg2 = 4,
    Ug = 5,
    Usg = 6,
    Vs = 7
}
/**
 * Options that can be specified when querying a model's bounding box
 *
 * Note that the options are not guaranteed to be supported by all models.
 */
export interface ModelBoundingBoxOptions {
    /**
     * By default, the model's bounding box will only include visible parts. Setting this option to true
     * will include all parts in the bounding box calculation for models that support it. Default is false.
     */
    includeHiddenParts?: boolean;
}
/**
 * Common interface for all models.
 */
export abstract class Model {
    /**
     * Name of the model.
     *
     * Mainly used for debugging.
     */
    abstract readonly name: string;
    /**
     * Returns the current {@link BoundingBox} (in world coordinates) of the model.
     *
     * When called without any parameters this method will return the current bounding box of the model, including only
     * visible parts/objects. For models that support it, the full bounding box can may queried by specifying the
     * optional {@link ModelBoundingBoxOptions} and setting {@link ModelBoundingBoxOptions.includeHiddenParts} to true.
     */
    abstract getBoundingBox(options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Can return an optional default camera configuration for this model.
     *
     * If a model returns a default camera config, any views displaying the model may utilize the information to do first-time
     * setup of their camera. The camera config will not have any effect on views where the camera has already been set by the user.
     * If multiple models are shown in the same view, the first model with a default camera config will take precedence.
     */
    abstract getDefaultCameraConfig(): CameraConfig | null;
}

/**
 * The possible navigation types. Used to specify {@link NavigationMouseButtonConfig}.
 */
export enum NavigationType {
    /** No navigation */
    NONE = 0,
    /** Pan */
    PAN = 1,
    /** Zoom the camera by modifying the field of view */
    ZOOM = 2,
    /** Walk in/out of model by moving the camera position (eye)  */
    WALK = 3,
    /** Rotate */
    ROTATE = 4,
    /** Rotate around the two screen axes. Should be used in combination with ROLL */
    ROTATE_SCREEN_AXES = 5,
    /** Roll, rotate around the view direction */
    ROLL = 6
}
/**
 * Controls behavior of mouse wheel zoom and walk
 */
export enum MouseWheelZoomAndWalkBehavior {
    /** Zooms in and out towards viewport center */
    TO_CENTER = 0,
    /** Zoom in towards mouse cursor */
    IN_TO_CURSOR = 1,
    /** Zoom in and out towards mouse cursor */
    IN_OUT_TO_CURSOR = 2
}
/**
 *  Navigation configuration for a particular mouse button.
 */
export interface NavigationMouseButtonConfig {
    /**
     * Navigation type to activate when no modifier keys are pressed.
     */
    noModifier: NavigationType;
    /**
     * Navigation type to activate when shift key is pressed.
     */
    shiftModifier: NavigationType;
    /**
     * Navigation type to activate when ctrl key is pressed, or for macs, when cmd key is pressed.
     */
    ctrlOrCmdModifier: NavigationType;
}
/**
 * Navigation configuration for a view.
 *
 * Specify how mouse and touch input should be used to navigate the view (move the camera).
 *
 * Note: To use the right mouse button (either rightMouseButton or leftAndRightMouseButtons), you
 * need to disable the default context menu in the browser (see example below).
 *
 * **Example on how to configure "Envision style" navigation:**
 *
 * ```
 * // Disable context menu - Required for enableMouseButtonTracking
 * canvas.addEventListener("contextmenu", (event) => { event.preventDefault()});
 *
 * // Enable mouse tracking (so we can use leftAndRightMouseButtons)
 * viewer.enableMouseButtonTracking(true);
 *
 * // Envision style navigation
 * const navConfig = view.navigation.config;
 * navConfig.leftMouseButton.noModifier =cee.NavigationType.PAN;
 * navConfig.rightMouseButton.noModifier =cee.NavigationType.ROTATE;
 * navConfig.leftAndRightMouseButtons.noModifier =cee.NavigationType.WALK;
 * navConfig.wheelOrPinch = cee.NavigationType.WALK;
 * ```
 */
export interface NavigationConfig {
    /**
     * Navigation config for left mouse button.
     *
     * Default is
     *
     * -  no modifiers -> ROTATE
     * -  shift pressed -> WALK
     * -  ctrl or cmd pressed -> PAN
     *
     */
    readonly leftMouseButton: NavigationMouseButtonConfig;
    /**
     * Navigation config for right mouse button.
     *
     * Default is NONE for all modifier states.
     */
    readonly rightMouseButton: NavigationMouseButtonConfig;
    /**
     * Navigation config for middle mouse button.
     *
     * Default is NONE for all modifier states.
     */
    readonly middleMouseButton: NavigationMouseButtonConfig;
    /**
     * Navigation config when both left and right mouse buttons are pressed.
     *
     * Default is NONE for all modifier states.
     *
     * Note: To use the leftAndRightMouseButtons you have to enable mouse tracking in the viewer.
     * See {@link Viewer.enableMouseButtonTracking}. This again requires the browser context menu to be disabled
     */
    readonly leftAndRightMouseButtons: NavigationMouseButtonConfig;
    /**
     * Navigation type to use for mouse wheel/touch screen pinch events.
     *
     * Default is WALK
     */
    wheelOrPinch: NavigationType;
    /**
     * Navigation type to use for one finger dragging.
     *
     * Default is ROTATE
     */
    oneFinger: NavigationType;
    /**
     * Navigation type to use for two finger dragging.
     *
     * Default is PAN
     */
    twoFinger: NavigationType;
    /**
     * Invert zoom or walk. If true, camera will zoom out if mouse is moved up
     *
     * Default is false
     */
    invertWalkZoom: boolean;
    /**
     * Invert the zoom direction of the mouse wheel
     *
     * Default is false
     */
    invertWheel: boolean;
}
/**
 * Class for controlling interactive navigation in a view
 *
 * You can specify the navigation scheme for the left mouse button, set the rotation point and
 * control the minimum walk target distance (for Walk navigation).
 *
 * You can access the navigation object with the {@link View.navigation} property.
 */
export class Navigation {
    /**
     * The navigation configuration.
     *
     * Specify what should happen on mouse and touch input
     */
    get config(): NavigationConfig;
    /**
     * The current rotation point
     */
    get rotationPoint(): Vec3Like;
    /**
     *
     */
    set rotationPoint(rotationPoint: Vec3Like);
    /**
     * The minimum walk target minTargetDistance
     *
     * For walk navigation, this is used to control how much the navigation should slow down when getting
     * close to the rotation point. The walk speed is dynamic so you can interact with large models.
     * Depending on your model size, you might want to adjust this parameter.
     *
     * The default is undefined (automatic), which will be interpreted as 1/10 of the current view bounding box.
     */
    get minWalkTargetDistance(): number | undefined;
    set minWalkTargetDistance(minTargetDistance: number | undefined);
    /**
     * Rotation sensitivity
     *
     * Sensitivity factor controlling how sensitive the mouse is when doing rotations.
     *
     * Default 1.0
     */
    get rotationSensitivity(): number;
    set rotationSensitivity(sensitivity: number);
    /**
     * Determine mouse wheel zoom and walk behavior
     *
     * This setting will only have effect if mouse wheel is configured to perform zoom or walk navigation.
     */
    get mouseWheelZoomAndWalkBehavior(): MouseWheelZoomAndWalkBehavior;
    set mouseWheelZoomAndWalkBehavior(behavior: MouseWheelZoomAndWalkBehavior);
}

export class NavigationOperator extends Operator {
    constructor(name?: string);
    /**
     * The navigation configuration.
     * Specify what should happen on mouse and touch input
     */
    get config(): OperatorConfig<NavigationType>;
    set config(config: OperatorConfig<NavigationType>);
    /**
     * Invert the zoom direction of the mouse wheel
     */
    get invertWalkZoom(): boolean;
    set invertWalkZoom(invert: boolean);
    /**
     * The current rotation point
     */
    get rotationPoint(): Vec3Like;
    set rotationPoint(rotationPoint: Vec3Like);
    /**
     * Reset the rotation point to the bounding box center of all models in the owner view.
     * If the operator does not have a valid view bounding box, the rotation point will not be
     * modified and the function will return false.
     */
    resetRotationPoint(): boolean;
    /**
     * An optional user provided axis around which the model should be rotated.
     * Set to null to not constrain rotation to an axis (default).
     */
    get rotationAxis(): Vec3Like | null;
    set rotationAxis(axis: Vec3Like | null);
    /**
     * The minimum walk target minTargetDistance
     *
     * For walk navigation, this is used to control how much the navigation should slow down when getting
     * close to the rotation point. The walk speed is dynamic so you can interact with large models.
     * Depending on your model size, you might want to adjust this parameter.
     *
     * The default is undefined (automatic), which will be interpreted as 1/10 of the current view bounding box.
     */
    get minWalkTargetDistance(): number | undefined;
    set minWalkTargetDistance(minTargetDistance: number | undefined);
    /**
     * Rotation sensitivity
     *
     * Sensitivity factor controlling how sensitive the mouse is when doing rotations.
     *
     * Default 1.0
     */
    get rotationSensitivity(): number;
    set rotationSensitivity(sensitivity: number);
    /**
     * Determine mouse wheel zoom and walk behavior
     *
     * This setting will only have effect if mouse wheel is configured to perform zoom or walk navigation.
     */
    get mouseWheelZoomAndWalkBehavior(): MouseWheelZoomAndWalkBehavior;
    set mouseWheelZoomAndWalkBehavior(behavior: MouseWheelZoomAndWalkBehavior);
    onAddedToView(): void;
    onMouseDown(event: MouseEvent): OperatorEventStatus;
    onMouseUp(event: MouseEvent): OperatorEventStatus;
    onMouseMove(event: MouseEvent): OperatorEventStatus;
    onWheel(event: WheelEvent): OperatorEventStatus;
    onTouchStart(event: TouchEvent): OperatorEventStatus;
    onTouchMove(event: TouchEvent): OperatorEventStatus;
    onTouchEnd(event: TouchEvent): OperatorEventStatus;
}

/** @module cee */ /** */
/**
 * The {@link OperatorEventStatus} enum is used to indicate to the {@link cee.OperatorStack} whether the event
 * should be propagated to the next operator in the stack, or if it should be stopped.
 */
export enum OperatorEventStatus {
    PROPAGATE = 0,
    DO_NOT_PROPAGATE = 1
}
/**
 * The {@link Operator} class is the base class for all operators. A name is required for all operators, and
 * the name is used to identify the operator in the {@link cee.OperatorStack}.
 *
 * Operators contain optional methods that correspond to the different events that may occur in the view.
 * When an operator is set on a {@link View}, the operator can interact with its ownerView, but only that view.
 * The {@link cee.Viewer} sets the events listeners internally, and then fires the corresponding Operator event
 * handler method when the event is recieved.
 */
export abstract class Operator {
    constructor(name: string);
    /**
     * The name of the operator.
     * Built-in operator names can be referenced by the {@link StandardOperator} enum.
     */
    get name(): string;
    /**
     * Returns the {@link View} that this operator is set on.
     * If the operator is not on a view's {@link cee.OperatorStack}, null is returned.
     */
    get ownerView(): View | null;
    onAddedToView?(): void;
    onRemovedFromView?(): void;
    onMouseDown?(event: MouseEvent): OperatorEventStatus;
    onMouseMove?(event: MouseEvent): OperatorEventStatus;
    onMouseUp?(event: MouseEvent): OperatorEventStatus;
    onClick?(event: MouseEvent): OperatorEventStatus;
    onDblClick?(event: MouseEvent): OperatorEventStatus;
    onTouchStart?(event: TouchEvent): OperatorEventStatus;
    onTouchMove?(event: TouchEvent): OperatorEventStatus;
    onTouchEnd?(event: TouchEvent): OperatorEventStatus;
    onPointerDown?(event: PointerEvent): OperatorEventStatus;
    onPointerMove?(event: PointerEvent): OperatorEventStatus;
    onPointerUp?(event: PointerEvent): OperatorEventStatus;
    onWheel?(event: WheelEvent): OperatorEventStatus;
    onKeyDown?(event: KeyboardEvent): OperatorEventStatus;
    onKeyUp?(event: KeyboardEvent): OperatorEventStatus;
}
export interface OperatorConfig<T extends number> {
    /**
     * Left Mouse Button Config
    */
    leftMouseButton: MouseButtonConfig<T>;
    /**
     * Right Mouse Button Config
    */
    rightMouseButton: MouseButtonConfig<T>;
    /**
     * Middle Mouse Button Config
    */
    middleMouseButton: MouseButtonConfig<T>;
    /**
     * Config when both left and right mouse buttons are pressed.
     */
    leftAndRightMouseButtons: MouseButtonConfig<T>;
    /**
     * Behavior to use for mouse wheel/touch screen pinch events.
     */
    wheelOrPinch: T;
    /**
     * Behavior to use for one finger dragging.
     */
    oneFinger: T;
    /**
     * Behavior to use for two finger dragging.
     */
    twoFinger: T;
    /**
     * Invert the zoom direction of the mouse wheel
     *
     * Default is false
     */
    invertWheel: boolean;
}
export interface MouseButtonConfig<T extends number> {
    /**
     * Behavior to activate when no modifier keys are pressed.
     */
    noModifier: T;
    /**
     * Behavior to activate when shift key is pressed.
     */
    shiftModifier?: T;
    /**
     * Behavior to activate when ctrl key is pressed, or for macs, when cmd key is pressed.
     */
    ctrlOrCmdModifier?: T;
}

type GetOperatorType<S extends string | StandardOperator, T> = S extends StandardOperator ? StandardOperatorToTypeMap[S] : T;
interface StandardOperatorToTypeMap {
    [StandardOperator.NAVIGATION]: NavigationOperator;
}
/**
 * The {@link StandardOperator} enum contains the names of the built-in operators.
 */
export enum StandardOperator {
    NAVIGATION = "NavigationOperator"
}
/**
 * The {@link OperatorStack} manages registered {@link Operator} instances for a view. Any active operators on
 * the stack will be called in a "Last In, First Called" order. An operator event listener method (i.e. onMouseDown,
 * onWheel, onKeyDown, etc.) will return an {@link OperatorEventStatus} to indicate whether the particular
 * event should be propagated to the next operator in the stack, or if it should be stopped.
 *
 * Since multiple operators can be added to the stack and respond to the same single event, the order of
 * It is recommend that more global operators, such as the {@link cee!NavigationOperator NavigationOperator}, are added first,
 * and more specific and local operators are added last. This way, local operations can be captured and handled before
 * they are propagated to the more global operations, if so desired.
 *
 * When a new operator is pushed to the stack, the operator stack will track the reference to that operator object.
 * You can then use the {@link OperatorStack.get} method to retrieve a reference to the operator object by name (regardless
 * of whether that operator object is active and on the stack or not). The prevents the need to instantiate and
 * set up the same operator again, and preserves the state of any setup operators. If you push a new instance of an operator
 * with a previously used name, the old operator reference will be replaced with the new one.
 *
 * By default, the {@link OperatorStack} is empty when a {@link View} is created. It is the developers responsibility to add
 * any desired default operators in your application. You can remove operators with the {@link OperatorStack.pop},
 * {@link OperatorStack.remove}, or {@link OperatorStack.clear} methods.
 */
export class OperatorStack {
    /**
     * Returns the array of active {@link Operator} objects
     */
    get activeOperators(): Operator[];
    /**
     * Sets the hot key operator for this operator stack.
     * The hot key (Alt/Opt) can be held to temporarily use
     * this operator without reordering the stack. The operator
     * must already be in the stack to be used with the hot key. Other
     * stack operators will not be called while the hot key is held.
     * To remove the hot key operator designation, but keep the operator
     * on the stack, set the hot key operator to null.
    */
    get hotKeyOperator(): Operator | null;
    set hotKeyOperator(operator: Operator | null);
    /**
     * Returns a reference to the operator object with the given name and type.
     * The desired operator does not need to be active on the stack.
     * If the operator was pushed to the stack during the lifetime of the view,
     * it is registered and the reference to the operator can be returned.
     *
     * If the operator is not found, null will be returned. You can always
     * check if the operator is registered by using the {@link OperatorStack.has} method
     *
     * Exmaple usage:
     * ```typescript
     * // Standard Operator
     * const standardOperator = view.operators.get(cee.StandardOperator.OPERATOR_ENUM);
     *
     * // Custom User-Provided Operator
     * const myCustomOperator = view.operators.get(MyCustomOperatorName) as MyCustomOperator;
     * const myCustomOperator = view.operators.get<MyCustomOperator>(MyCustomOperatorName);
     *
     * // Generic Operator
     * const generic = view.operators.get("MyOperatorName");  // Returns Operator type w/o cast
     * ```
    */
    get<T extends Operator, S extends StandardOperator | string = string>(operatorName: S): GetOperatorType<S, T> | null;
    /**
     * Returns true if the operator has been registered with the operator stack.
    */
    has(operator: StandardOperator | string): boolean;
    /**
     * Returns the operator stack size
    */
    size(): number;
    /**
     * Adds an operator on the stack if it's not already on the stack
    */
    push(operator: Operator, setAsHotKeyOperator?: boolean): boolean;
    /**
     * Removes an operator from the top of the stack
    */
    pop(): Operator | undefined;
    /**
     * Sets an operator to the 0 based index position on the stack.
     * If there is already an operator in that position, it is replaced.
     * If the operator is already on the stack, it is moved to the requested position.
    */
    set(operator: Operator, position: number): boolean;
    /**
     * Returns the operator at the top of the stack
    */
    peek(): Operator | null;
    /**
     * Returns the index of an operator on the stack
     * If the operator is not found on the stack, -1 is returned.
    */
    indexOf(operator: Operator): number;
    /**
     * Removes an operator from the stack
    */
    remove(operatorInput: Operator | StandardOperator | string): void;
    /**
     * Removes all operators from the stack
    */
    clear(): void;
}
export {};

/**
 * Describes all the items on a navigation cube
 */
export enum NavigationCubeItem {
    NCI_NONE = 0,
    NCI_CORNER_XN_YN_ZN = 1,
    NCI_CORNER_XP_YN_ZN = 2,
    NCI_CORNER_XP_YP_ZN = 3,
    NCI_CORNER_XN_YP_ZN = 4,
    NCI_CORNER_XN_YN_ZP = 5,
    NCI_CORNER_XP_YN_ZP = 6,
    NCI_CORNER_XP_YP_ZP = 7,
    NCI_CORNER_XN_YP_ZP = 8,
    NCI_EDGE_YN_ZN = 9,
    NCI_EDGE_XP_ZN = 10,
    NCI_EDGE_YP_ZN = 11,
    NCI_EDGE_XN_ZN = 12,
    NCI_EDGE_YN_ZP = 13,
    NCI_EDGE_XP_ZP = 14,
    NCI_EDGE_YP_ZP = 15,
    NCI_EDGE_XN_ZP = 16,
    NCI_EDGE_XN_YN = 17,
    NCI_EDGE_XP_YN = 18,
    NCI_EDGE_XP_YP = 19,
    NCI_EDGE_XN_YP = 20,
    NCI_FACE_X_POS = 21,
    NCI_FACE_X_NEG = 22,
    NCI_FACE_Y_POS = 23,
    NCI_FACE_Y_NEG = 24,
    NCI_FACE_Z_POS = 25,
    NCI_FACE_Z_NEG = 26,
    NCI_ARROW_LEFT = 27,
    NCI_ARROW_RIGHT = 28,
    NCI_ARROW_TOP = 29,
    NCI_ARROW_BOTTOM = 30,
    NCI_HOME = 31,
    NCI_ROTATE_CW = 32,
    NCI_ROTATE_CCW = 33
}
/**
 * View configuration computed from the navigation cube item
 */
export interface NavigationCubeViewConfiguration {
    eye: Vec3Like;
    direction: Vec3Like;
    up: Vec3Like;
}
/**
 *  The position of an overlay item
 */
export enum OverlayItemPosition {
    TOP_LEFT = 0,
    TOP_RIGHT = 1,
    MIDDLE_LEFT = 2,
    MIDDLE_RIGHT = 3,
    BOTTOM_LEFT = 4,
    BOTTOM_RIGHT = 5
}
/**
 * Manages 2d overlay items in a View.
 *
 * Overlay items are 2d items drawn in the view together with the 3d model, for example color legends,
 * navigation cube, step text and info box.
 *
 * You can access the overlay object with the {@link View.overlay} property.
 */
export class Overlay {
    /**
     *
    */
    private constructor();
    /**
     * The visibility of the navigation cube in the view
     */
    get navigationCubeVisible(): boolean;
    /**  */
    set navigationCubeVisible(show: boolean);
    /**
     * Configure the navigation cube
     *
     * - faceNames: Must contain 6 values, names for: Pos_X, Neg_X, Pos_Y, Neg_Y, Pos_Z, Neg_Z
     * - faceColors: null or 6 values, colors for: Pos_X, Neg_X, Pos_Y, Neg_Y, Pos_Z, Neg_Z
     * axisLabels: null (defaults to x,y,z) or 3 values, names for X_AXIS, Y_AXIS, Z_AXIS
     */
    configureNavigationCube(faceNames: string[], faceColors?: Color3Like[], axisLabels?: string[]): void;
    /**
     * The view eye position to set when the "Home" button on the navigation cube is pressed
     * If undefined then eye position is set automatically to fit view
     */
    get navigationCubeHomeEye(): Vec3 | undefined;
    set navigationCubeHomeEye(eye: Vec3 | undefined);
    /**
     * The view direction to set when the "Home" button on the navigation cube is pressed
     */
    get navigationCubeHomeDirection(): Vec3;
    set navigationCubeHomeDirection(direction: Vec3);
    /**
     * The up direction to set when the "Home" button on the navigation cube is pressed
     */
    get navigationCubeHomeUp(): Vec3;
    set navigationCubeHomeUp(up: Vec3);
    /**
     * Get the view direction and up vector based on the navigation cube item
     */
    viewConfigurationFromNavigationCubeItem(item: NavigationCubeItem): NavigationCubeViewConfiguration;
    /**
     * The visibility of the info box (the blue box in the bottom right corner) in the view
     */
    get infoBoxVisible(): boolean;
    /**  */
    set infoBoxVisible(show: boolean);
    /**
     * The visibility of the step text (the text at the bottom of the view displaying the current step for RemoteModels)
     */
    get stepTextVisible(): boolean;
    /**  */
    set stepTextVisible(show: boolean);
    /**
     * Whether information from the models should be appended to the info box
     */
    get autoAppendModelInfoToInfoBox(): boolean;
    /**  */
    set autoAppendModelInfoToInfoBox(enable: boolean);
    /**
     * The visibility of the color legend overlay items for models (currently only for RemoteModel).
     */
    get modelColorLegendsVisible(): boolean;
    /**  */
    set modelColorLegendsVisible(show: boolean);
    /**
     * The maximum height of the legends (color legends and category legends).
     *
     * Legends are sized to fit the view, depending on the view height and the number of legends.
     * This property controls the maximum height a legend can have.
     *
     * The value of this property is in device pixels, so it's multiplied by the display's pixelScaleFactor to give
     * the native (full resolution) pixel height.
     */
    get maximumLegendHeight(): number;
    /**
     *
     *
     *
     *
     * */
    set maximumLegendHeight(height: number);
    /**
     * The position of the navigation cube.
     */
    get navigationCubePosition(): OverlayItemPosition;
    /**  */
    set navigationCubePosition(position: OverlayItemPosition);
    /**
     * The position of the legends.
     */
    get legendsPosition(): OverlayItemPosition;
    /**  */
    set legendsPosition(position: OverlayItemPosition);
    /**
     * The position of the info box.
     */
    get infoBoxPosition(): OverlayItemPosition;
    /**  */
    set infoBoxPosition(position: OverlayItemPosition);
    /**
     * Sets the text to show in the info box.
     *
     * Note that any information from the models will be appended to the given string unless {@link autoAppendModelInfoToInfoBox} is set to false.
     */
    setInfoBoxContent(content: string): void;
    /**
     * Sets the appearance of the info box.
     */
    setInfoBoxAppearance(backgroundColor?: Color4Like, textColor?: Color3Like, borderColor?: Color3Like): void;
    /**
     * Sets the text to show in as the step info.
     *
     * This will remove any automatic step info from the Remote Model.
     */
    setStepTextContent(content: string): void;
    /**
     * Adds a color legend displaying the settings of the given scalar mapper.
     *
     * Legends can be removed with the {@link removeAllCustomLegends} method.
     *
     * The resultId parameter is an optional user defined id identifying the scalar mapper. This id will be passed to the
     * legend picked handler when the user clicks on the color legend. See {@link Viewer.setColorLegendClickHandler} and
     * {@link ColorLegendClickedHandler} for more information.
     */
    addCustomColorLegendForScalarMapper(scalarMapper: ScalarMapperContinuousDomain, legendTitle: string, resultId: number): void;
    /**
     * Adds a color legend displaying the settings of the given scalar mapper.
     *
     * Legends can be removed with the {@link removeAllCustomLegends} method.
     */
    addCustomColorLegend(legend: OverlayColorLegendContinuousDomain): void;
    /**
     * Adds a category legend to the view.
     *
     * The category legend shows each color with its corresponding descriptive text.
     *
     * Note that the categories and colors arrays must have the same length.
     *
     * Legends can be removed with the {@link removeAllCustomLegends} method.
     */
    addCustomCategoryLegend(categories: string[], colors: ArrayLike<Color3Like>, legendTitle: string, resultId: number): void;
    /**
     * Removes all custom legends from the view.
     *
     * This method will remove all legends added with the {@link addCustomColorLegendForScalarMapper} and
     * {@link addCustomCategoryLegend} methods.
     */
    removeAllCustomLegends(): void;
}

/**
 * Color legend for all continuous domain scalar mappers.
 *
 * The OverlayColorLegendContinuousDomain is capable of visualizing all scalar mappers that
 * derives from the ScalarMapperContinuousDomain.
 */
export class OverlayColorLegendContinuousDomain {
    /**
     *
     */
    constructor(resultId: number);
    /**
     * The title of the color legend.
     *
     * The legend supports multi-line titles. Separate each line with a '\\n' character
     */
    get title(): string;
    set title(title: string);
    /**
     * The color of the legend text
     */
    get textColor(): Color3Like;
    set textColor(color: Color3Like);
    /**
     * The color of the border and tick marks
     */
    get lineColor(): Color3Like;
    set lineColor(color: Color3Like);
    /**
     * Sets that all tick marks should be evenly distributed in the color legend, despite the uneven size of
     * each level.
     *
     * The default value is true, which will render a color legend where all the levels
     * have the same size or all the continuous custom tick marks with even spacing.
     */
    get forceUniformTickMarkSpacing(): boolean;
    set forceUniformTickMarkSpacing(force: boolean);
    /**
     * Specify if the tick mark lines should be drawn on top of the color legend or just on the side of it.
     */
    get drawTickMarksOnTopOfLegendBar(): boolean;
    set drawTickMarksOnTopOfLegendBar(drawOnTop: boolean);
    /**
     * Specifies if the tick mark labels (usually the number values) should be shown together with
     * the tick mark lines.
     */
    get showTickMarkLabels(): boolean;
    set showTickMarkLabels(show: boolean);
    /**
     * Set custom labels that will be drawn at the given relative position on the color legend
     */
    setCustomLabels(labels: string[], relativePositions: number[]): void;
    /**
     * Clear the custom labels
     */
    clearCustomLabels(): void;
    /**
     * Configure the color legend from the given scalar mapper
     */
    setupFromScalarMapper(scalarMapper: ScalarMapperContinuousDomain): void;
    /**
     * Specify custom tick marks to use
     *
     * setupFromScalarMapper will setup default tick marks. Use this method to override this and use
     * custom tick mark values.
     */
    setTickValues(values: ArrayLike<number>, scalarMapper: ScalarMapperContinuousDomain): void;
}

/**
 * Interface describing an object with A,B,C,D properties.
 */
export interface PlaneLike {
    /** The A coefficient of the plane equation */
    readonly A: number;
    /** The B coefficient of the plane equation */
    readonly B: number;
    /** The C coefficient of the plane equation */
    readonly C: number;
    /** The D coefficient of the plane equation */
    readonly D: number;
}
/**
 * An immutable plane.
 *
 * The class describes a plane by the equation: Ax + By + Cz + D = 0
 * The plane's normal is defined by the coefficients [A, B, C]
 *
 */
export class Plane {
    /**
     * Constructor
     */
    constructor(A: number, B: number, C: number, D: number);
    /**
     * The A coefficient of the plane equation
     */
    get A(): number;
    /**
     * The B coefficient of the plane equation
     */
    get B(): number;
    /**
     * The C coefficient of the plane equation
     */
    get C(): number;
    /**
     * The D coefficient of the plane equation
     */
    get D(): number;
    /**
     * Returns the distance between the give point and this plane
     */
    getDistance(point: Vec3Like): number;
    /**
     * Returns the square of the distance from the point to the plane
     *
     * The square of the distance is relatively fast to compute (no 'sqrt') and is useful for determine
     * which side the point is on. To obtain the actual distance, divide by sqrt(A^2 + B^2 + C^2)
     * or use the distance() function directly.
     */
    getDistanceSquared(point: Vec3Like): number;
    /**
     * Returns a point guaranteed to be on this plane
     */
    getPointInPlane(): Vec3Like;
    /**
     * Returns the distance between the give point and this plane
     */
    getNormal(): Vec3Like;
    /**
     * Project the given point onto the plane
     */
    projectPoint(point: Vec3Like): Vec3Like;
    /**
     * Project the given vector onto the plane
     *
     * Returns the projected vector or undefined if the vector is parallel with the plane's normal
     */
    projectVector(vector: Vec3Like): Vec3Like | null;
    /**
     * Returns true if the planes are equal.
     */
    equals(other: PlaneLike): boolean;
    /**
     * Creates a plane instance from any object with A,B,C,D properties
     */
    static from(plane: PlaneLike): Plane;
    /**
     * Returns a plane created from a point and a normal
     */
    static fromPointAndNormal(point: Vec3Like, normal: Vec3Like): Plane;
    /**
     * Returns a plane created from three points
     *
     * The three points cannot be on a line as they need to define a plane.
     * So (p2 - p1)*(p3 - p1) != 0
     */
    static fromPoints(p1: Vec3Like, p2: Vec3Like, p3: Vec3Like): Plane;
}

/** @module cee */ /** */
/**
 * Interface for models that require the framework to do background model processing
 */
export interface ProcessableModel {
}

/** @module cee */ /** */
/**
 * An immutable min / max range
 */
export class Range {
    /**
     *
     */
    readonly minimum: number;
    /**
     *
     */
    readonly maximum: number;
    /**
     *
     */
    constructor(min: number, max: number);
    /**
     *  Returns true if the range is valid, i.e. if minimum <= maximum
     */
    isValid(): boolean;
}

/** @module cee */ /** */
/**
 * A 3d ray used, for example, for picking on the 3D model.
 */
export class Ray {
    /**
     * The origin of the ray in world coordinates.
     */
    get origin(): Vec3Like;
    set origin(origin: Vec3Like);
    /**
     * The direction vector of the ray in world coordinates.
     */
    get direction(): Vec3Like;
    set direction(direction: Vec3Like);
    /**
     * Creates a Ray object
     */
    constructor(origin: Vec3Like, direction: Vec3Like);
    /**
     * Returns a clone of the ray.
     */
    clone(): Ray;
    /**
     * Transforms the ray with the given matrix.
     *
     * The origin will be transformed as a point, and the direction as a vector.
     */
    transform(matrix: Mat4): void;
    /**
     * Returns the squared distance from the point to the ray
     */
    pointDistanceSquared(point: Vec3Like): number;
    /**
     * Returns the intersection point of this ray with the given plane, or null if no intersection.
     */
    planeIntersect(plane: Plane): Vec3Like | null;
}

/** @module cee */ /** */
/**
 * Helper class for computing the intersection between a ray and number of points with a given threshold
 * (the radius).
 */
export class RaySphereIntersector {
    /**
     * Returns the index of the closest intersected sphere to the ray
     *
     * The spheres are defined with a radius and an array of points in the pointsArr array
     *
     * The pointsArr array contains a number of sphere centers in a 1d array:
     * <s1.x, s1.y, s1.z, s2.x, s2.y, s2.z> ...
     */
    static findClosestIntersectedSphereToRay(ray: Ray, radius: number, pointsArr: ArrayLike<number>): number;
    /**
     * Find all the points (spheres) intersected by the ray, and return them ordered by the distance
     * to the Ray (closest first).
     *
     * The spheres are defined with a radius and an array of points in the pointsArr array
     *
     * The pointsArr array contains a number of sphere centers in a 1d array:
     * <s1.x, s1.y, s1.z, s2.x, s2.y, s2.z> ...
     */
    static findAllIntersectedSpheresOrderedByDistanceToRay(ray: Ray, radius: number, pointsArr: ArrayLike<number>): {
        index: number;
        l2Distance: number;
    }[];
}

/** @module cee */ /** */
/**
 * Abstract base class for scalar mappers.
 *
 * The scalar mapper offers two services:
 *
 * - Map from a scalar value (domain value) to a texture coordinate or a color
 * - Create a texture from the scalar mapper that can be used for rendering and corresponds with
 *   the texture coordinates produced.
 */
export interface ScalarMapper {
    mapToColor(scalarValue: number): Color4Like;
    mapToTextureCoordinate(scalarValue: number): Vec2Like;
    createTexture(): Texture;
}

/** @module cee */ /** */
/**
 *
 * Maps scalar values to texture coordinates/colors using a filled contours style color map with
 * levels of uniform size.
 *
 * To show a color legend in the view representing this mapper, use the {@link Overlay.addCustomColorLegendForScalarMapper}
 * function.
 */
export class ScalarMapperContinuous extends ScalarMapperContinuousDomain {
    /**
     *
     */
    constructor();
    /**
     * The minimum range of the mapper
     */
    get rangeMinimum(): number | undefined;
    /**
     * The maximum range of the mapper
     */
    get rangeMaximum(): number | undefined;
    /**
     * True if the mapper is setup to logarithmic mapping
     */
    get logarithmic(): boolean;
    /**
     * Sets the range of the mapper. The mapper will map domain values to colors based on an
     * even distribution between the given min and max values.
     */
    setRange(min: number, max: number): void;
    /**
     * Sets a logarithmic range of the mapper.
     */
    setRangeLogarithmic(min: number, max: number): void;
    /**
     *
     */
    setColors(colors: Color4Like[]): void;
    /**
     *
     */
    setColorsFromColorTable(colorTable: ColorTable): void;
    /**
     *
     */
    setColorsAtValues(colorArr: ArrayLike<Color4Like>, valueArr: ArrayLike<number>): void;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToColor(scalarValue: number): Color4Like;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToTextureCoordinate(scalarValue: number): Vec2Like;
    /**
     * Creates and returns texture for this scalar mapper
     */
    createTexture(): Texture;
    /**
     * Map domain value (range_min -> range_max) into a normalized value (0 -> 1)
     */
    normalizedValue(domainValue: number): number;
    /**
     * Map normalized value (0 -> 1) into a domain value (range_min -> range_max)
     */
    domainValue(normalizedPosition: number): number;
    /**
     *
     */
    version(): number;
    /**
     *
     */
    tickValuesHint(): ArrayLike<number>;
}

/** @module cee */ /** */
/**
 * Base class for scalar mappers that implement normalizedValue / domainValue
 */
export abstract class ScalarMapperContinuousDomain implements ScalarMapper {
    abstract mapToColor(scalarValue: number): Color4Like;
    abstract mapToTextureCoordinate(scalarValue: number): Vec2Like;
    abstract createTexture(): Texture;
    abstract normalizedValue(domainValue: number): number;
    abstract domainValue(normalizedPosition: number): number;
    abstract version(): number;
    abstract tickValuesHint(): ArrayLike<number>;
    /**
     * The color to assign values that are above the given range.
     *
     * Default is undefined, which indicates that the last color in the color array will be used.
     */
    get aboveRangeColor(): Color4Like | null;
    set aboveRangeColor(color: Color4Like | null);
    /**
     * The color to assign values that are below the given range.
     *
     * Default is null, which indicates that the first color in the color array will be used.
     */
    get belowRangeColor(): Color4Like | null;
    set belowRangeColor(color: Color4Like | null);
    /**
     * The color used for undefined values.
     */
    get undefinedColor(): Color4Like;
    set undefinedColor(color: Color4Like);
}

/** @module cee */ /** */
/**
 * Maps scalar values to texture coordinates/colors using a continuous/gradient style color map with
 * multiple segments of independent gradients.
 *
 * This scalar mapper is configured much in the same way as the ScalarMapperFilledContours, but here
 * you are allowed to specify a bottom and top color for each level/segment.
 */
export class ScalarMapperContinuousPiecewise extends ScalarMapperContinuousDomain {
    /**
     *
     */
    constructor();
    /**
     * The minimum range of the mapper
     */
    get rangeMinimum(): number | undefined;
    /**
     * The maximum range of the mapper
     */
    get rangeMaximum(): number | undefined;
    /**
     * Sets the scalar mapper from the given tick values array and colors from/to
     *
     * The tickValuesArray will contain the values separating each segment of the scalar mapper.
     * The first value in tickValuesArray will be the min value of the scalar mapper, the last value
     * will be the max value of the scalar mapper.
     *
     * The colorsFromToArray contains bottom and top colors for each of the segments. colorsFromToArray[0]
     * is the bottom of the first segment, colorsFromToArray[1] is the top of the first segment.
     *
     * The colorsFromToArray.size must be 2*(tickValuesArray.length - 1)
     */
    setup(colorsFromToArray: ArrayLike<Color4Like>, tickValuesArray: ArrayLike<number>): void;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToColor(scalarValue: number): Color4Like;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToTextureCoordinate(scalarValue: number): Vec2Like;
    /**
     * Creates and returns texture for this scalar mapper
     */
    createTexture(): Texture;
    /**
     * Map domain value (range_min -> range_max) into a normalized value (0 -> 1)
     */
    normalizedValue(domainValue: number): number;
    /**
     * Map normalized value (0 -> 1) into a domain value (range_min -> range_max)
     */
    domainValue(normalizedPosition: number): number;
    /**
     *
     */
    version(): number;
    /**
     *
     */
    tickValuesHint(): ArrayLike<number>;
}

/** @module cee */ /** */
/**
 *
 * Maps scalar values to texture coordinates/colors using a filled contours style color map with
 * levels of uniform size.
 *
 * Configured by specifying the colors and their values with the method {@link setColorsAtValues}.
 *
 * To show a color legend in the view representing this mapper, use the {@link Overlay.addCustomColorLegendForScalarMapper}
 * function.
 */
export class ScalarMapperFilledContours extends ScalarMapperContinuousDomain {
    /**
     *
     */
    constructor();
    /**
     * The minimum range of the mapper
     */
    get rangeMinimum(): number | undefined;
    /**
     * The maximum range of the mapper
     */
    get rangeMaximum(): number | undefined;
    /**
     * Sets the scalar mapper level colors from an array of colors at the given values
     */
    setColorsAtValues(colorArr: ArrayLike<Color4Like>, valueArr: ArrayLike<number>): void;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToColor(scalarValue: number): Color4Like;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToTextureCoordinate(scalarValue: number): Vec2Like;
    /**
     * Creates and returns texture for this scalar mapper
     */
    createTexture(): Texture;
    /**
     * Map domain value (range_min -> range_max) into a normalized value (0 -> 1)
     */
    normalizedValue(domainValue: number): number;
    /**
     * Map normalized value (0 -> 1) into a domain value (range_min -> range_max)
     */
    domainValue(normalizedPosition: number): number;
    /**
     * Returns the version of the scalar mapper. Version is increased whenever the mapper is changed.
     */
    version(): number;
    /**
     * Returns the suggest tick values (the values of the color changes)
     */
    tickValuesHint(): ArrayLike<number>;
}

/** @module cee */ /** */
/**
 *
 * Maps scalar values to texture coordinates/colors using a filled contours style color map with
 * levels of uniform size.
 *
 * Configured by specifying the number of level colors ({@link colorArray}) and the range ({@link setRange}).
 *
 * To show a color legend in the view representing this mapper, use the {@link Overlay.addCustomColorLegendForScalarMapper}
 * function.
 */
export class ScalarMapperFilledContoursUniform extends ScalarMapperContinuousDomain {
    /**
     *
     */
    constructor();
    /**
     * The minimum range of the mapper
     */
    get rangeMinimum(): number | undefined;
    /**
     * The maximum range of the mapper
     */
    get rangeMaximum(): number | undefined;
    /**
     * The colors to use for the mapper.
     */
    get colorArray(): ArrayLike<Color4Like>;
    set colorArray(colors: ArrayLike<Color4Like>);
    /**
     * Sets the range of the mapper. The mapper will map domain values to colors based on an
     * even distribution between the given min and max values.
     */
    setRange(min: number, max: number): void;
    /**
     * Sets a logarithmic range of the mapper.
     */
    setRangeLogarithmic(min: number, max: number): void;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToColor(scalarValue: number): Color4Like;
    /**
     * Maps the given domain value to a color using the current range and color array.
     */
    mapToTextureCoordinate(scalarValue: number): Vec2Like;
    /**
     * Creates and returns texture for this scalar mapper
     */
    createTexture(): Texture;
    /**
     * Map domain value (range_min -> range_max) into a normalized value (0 -> 1)
     */
    normalizedValue(domainValue: number): number;
    /**
     * Map normalized value (0 -> 1) into a domain value (range_min -> range_max)
     */
    domainValue(normalizedPosition: number): number;
    /**
     * Returns the version of the scalar mapper. Version is increased whenever the mapper is changed.
     */
    version(): number;
    /**
     * Returns the suggest tick values (the values of the color changes)
     */
    tickValuesHint(): ArrayLike<number>;
}

/**
 * Helper class for implementing Snap-to features in an application
 *
 * To snap to a point on while checking if the point is visible (not obscured by the model(s)):
 *
 * ```javascript
 *  // Get the ray at mouse position
 * const ray = myViewer.rayFromCssCoordinate(myView, event.offsetX, event.offsetY);
 *
 * // Find the radius to use based on model extent
 * const modelBoundingBox = myModel.getBoundingBox();
 * const radius = modelBoundingBox.getExtent().getLength()/100;
 * let closestPoint = null;
 *
 * // Snap to point, check if visible
 * const snapPointPicker = new cee.SnapPointPicker(myView, ray, radius);
 * const pointIndex = snapPointPicker.findClosestPoint(myHotSpots);
 *
 * if (pointIndex >= 0) {
 *     closestPoint = new cee.Vec3(myHotSpots[3*pointIndex],
 *        myHotSpots[3*pointIndex + 1], myHotSpots[3*pointIndex + 2]);
 * }
 * ```
 *
 * To just find the closest point to the view, not checking the model if the point is visible:
 * ```javascript
 * // Snap to closest point, not checking the model
 * const pointIndex = cee.RaySphereIntersector.findClosestIntersectedSphereToRay(ray, radius, g.hotSpots);
 *
 * if (pointIndex >= 0) {
 *     closestPoint = new cee.Vec3(g.hotSpots[3*pointIndex],
 *        g.hotSpots[3*pointIndex + 1], g.hotSpots[3*pointIndex + 2]);
 * }
 *
 * ```
 */
export class SnapPointPicker {
    constructor(view: View, ray: Ray, radius: number);
    /**
     * Find the point closest to the ray that is visible (not obscured by the model).
     *
     * The radius determines the maximum distance from the point in order to snap to it.
     *
     * The pointsArr array contains a number of points (sphere centers) in a 1d array:
     * <s1.x, s1.y, s1.z, s2.x, s2.y, s2.z> ...
     *
     * Returns the index of the closest visible point. -1 if there was not hit.
     */
    findClosestPoint(pointsArr: ArrayLike<number>): number;
}

/**
 * Specifies what should happen to texture coordinates that are outside the 0 to 1 range
 */
export enum TextureWrapMode {
    /**
     * The integer part of the coordinate will be ignored and a repeating pattern is formed.
     */
    REPEAT = 0,
    /**
     * The texture coordinates will be clamped into the range 0 to 1
     */
    CLAMP_TO_EDGE = 1
}
/**
 * Specifies the minifying filtering used when doing the texture mapping.
 */
export enum TextureMinFilter {
    /**
     * Nearest neighbor filtering on the base MipMap level. Texture will look blocky when zoom into.
     */
    NEAREST = 0,
    /**
     * Linear filtering on the base MipMap level. (Default magnification filter in OpenGL). Texture will look blurry when zoomed into.
     */
    LINEAR = 1,
    /**
     * Selects nearest MipMap level and performs nearest neighbor filtering.
     */
    NEAREST_MIPMAP_NEAREST = 2,
    /**
     * Perform linear interpolation between MipMap levels and perform nearest neighbor filtering. (Default minifying filter in OpenGL).
     */
    NEAREST_MIPMAP_LINEAR = 3,
    /**
     * Selects nearest MipMap level and performs linear filtering.
     */
    LINEAR_MIPMAP_NEAREST = 4,
    /**
     * Perform linear interpolation between MipMap levels and perform linear filtering (trilinear mipmapping).
     */
    LINEAR_MIPMAP_LINEAR = 5
}
/**
 * Specifies the magnification filtering used when doing the texture mapping.
 */
export enum TextureMagFilter {
    /**
     * Nearest neighbor filtering on the base MipMap level.
     */
    NEAREST = 0,
    /**
     * Linear filtering on the base MipMap level. (Default magnification filter in OpenGL).
     */
    LINEAR = 1
}
/**
 * Options for a {@link Texture} object.
 */
export class TextureOptions {
    /**
     * If true, mip maps will be generated for the texture (default true). Mip maps will give a better visual appearance
     * when the texture is smaller in screen pixels than the texture image.
     */
    generateMipmaps?: boolean;
    /**
     * Specifies what should happen to texture coordinates that are outside the 0 to 1 range
     */
    wrapMode?: TextureWrapMode;
    /**
     * Specifies the minifying filtering used when doing the texture mapping.
     */
    minFilter?: TextureMinFilter;
    /**
     * Specifies the magnification filtering used when doing the texture mapping.
     */
    magFilter?: TextureMagFilter;
}
/**
 * Factory for creating texture objects
 *
 */
export class Texture {
    /**
     * Private constructor
     */
    private constructor();
    /**
     * Creates a texture image object from ImageData
     *
     * **Note:** A general rule is that both dimensions must be a power of two.
     *
     * To avoid this limitation, pass in texture options with
     * generateMipmaps set to false, wrapMode set to TextureWrapMode.CLAMP_TO_EDGE and minFilter set to LINEAR or NEAREST. E.g.:
     * ```javascript
     * const texture = cee.Texture.fromImageData(imageData,
     *     { generateMipmaps: false,
     *       wrapMode: cee.TextureWrapMode.CLAMP_TO_EDGE,
     *       minFilter: cee.TextureMinFilter.LINEAR
     *     });
     * ```
     */
    static fromImageData(imageData: ImageData, textureOptions?: TextureOptions): Texture;
    /**
     * Creates a texture image object from an HTMLImageElement
     *
     * **Note:** A general rule is that both dimensions must be a power of two.
     *
     * To avoid this limitation, pass in texture options with
     * generateMipmaps set to false, wrapMode set to TextureWrapMode.CLAMP_TO_EDGE and minFilter set to LINEAR or NEAREST. E.g.:
     * ```javascript
     * const texture = cee.Texture.fromImageData(imageData,
     *     { generateMipmaps: false,
     *       wrapMode: cee.TextureWrapMode.CLAMP_TO_EDGE,
     *       minFilter: cee.TextureMinFilter.LINEAR
     *     });
     * ```
     */
    static fromHTMLImageElement(htmlImageElement: HTMLImageElement, textureOptions?: TextureOptions): Texture;
}

/** @module cee */ /** */
/**
 * Interface describing an object with x,y properties.
 */
export interface Vec2Like {
    /** The x coordinate of the vector */
    readonly x: number;
    /** The y coordinate of the vector */
    readonly y: number;
}
/**
 * An immutable 2d vector with x, y  values.
 *
 * Used e.g. for texture coordinates
 */
export class Vec2 {
    /**
     * The x coordinate of the vector
     */
    readonly x: number;
    /**
     * The y coordinate of the vector
     */
    readonly y: number;
    /**
     * Constructor
     */
    constructor(x: number, y: number);
    /**
     * Returns true if the vectors are equal
     */
    equals(other: Vec2Like): boolean;
    /**
     * Returns the squared length of the vector
     */
    getLengthSquared(): number;
    /**
     * Returns the length of the vector (sqrt(x^2 + y^2)).
     */
    getLength(): number;
    /**
     * Returns a normalized version of the vector.
     */
    getNormalized(): Vec2;
    /**
     * Returns a negated version of the vector.
     */
    getNegated(): Vec2;
    /**
     * Returns the result of adding the two vectors
     */
    static add(a: Vec2Like, b: Vec2Like): Vec2;
    /**
     * Returns the result of subtracting vector b from vector a
     */
    static sub(a: Vec2Like, b: Vec2Like): Vec2;
    /**
     * Returns the dot product of the 2 vectors
     */
    static dot(a: Vec2Like, b: Vec2Like): number;
    /**
     * Returns the result of scaling the given vector by the given factor
     */
    static scale(vec: Vec2Like, factor: number): Vec2;
    /**
     * Returns the negation of the given vector
     */
    static negate(vec: Vec2Like): Vec2;
    /**
     * Creates a new Vec2 instance from any object with x and y properties.
     */
    static from(vec: Vec2Like): Vec2;
    /**
     * Creates a new Vec2 instance from the first 2 elements of the given array.
     */
    static fromArray(arr: ArrayLike<number>): Vec2;
}

/** @module cee */ /** */
/**
 * Interface describing an object with x,y,z properties.
 */
export interface Vec3Like {
    /** The x coordinate of the vector */
    readonly x: number;
    /** The y coordinate of the vector */
    readonly y: number;
    /** The z coordinate of the vector */
    readonly z: number;
}
/**
 * An immutable 3d vector with x, y and z values.
 *
 * Used for positions, normals and other 3d entities.
 */
export class Vec3 {
    /**
     * The x coordinate of the vector
     */
    readonly x: number;
    /**
     * The y coordinate of the vector
     */
    readonly y: number;
    /**
     * The z coordinate of the vector
     */
    readonly z: number;
    /**
     * Constructor
     */
    constructor(x: number, y: number, z: number);
    /**
     * Returns true if the vectors are equal
     */
    equals(other: Vec3Like): boolean;
    /**
     * Returns the squared length of the vector
     */
    getLengthSquared(): number;
    /**
     * Returns the length of the vector (sqrt(x^2 + y^2 + z^2)).
     */
    getLength(): number;
    /**
     * Returns a normalized version of the vector.
     */
    getNormalized(): Vec3;
    /**
     * Returns a negated version of the vector.
     */
    getNegated(): Vec3;
    /**
     * Returns the squared distance between this point and otherPoint
     */
    getPointDistanceSquared(otherPoint: Vec3Like): number;
    /**
     * Returns the distance between this point and otherPoint
     */
    getPointDistance(otherPoint: Vec3): number;
    /**
     * Returns the result of adding the two vectors
     */
    static add(a: Vec3Like, b: Vec3Like): Vec3;
    /**
     * Returns the result of subtracting vector b from vector a
     */
    static sub(a: Vec3Like, b: Vec3Like): Vec3;
    /**
     * Returns the dot product of the 2 vectors
     */
    static dot(a: Vec3Like, b: Vec3Like): number;
    /**
     * Returns the cross product of the 2 vectors
     */
    static cross(a: Vec3Like, b: Vec3Like): Vec3;
    /**
     * Returns the result of scaling the given vector by the given factor
     */
    static scale(vec: Vec3Like, factor: number): Vec3;
    /**
     * Returns the negation of the given vector
     */
    static negate(vec: Vec3Like): Vec3;
    /**
     * Returns a new vector with the given vector transforms as a point.
     *
     * Transforms the vector as a point by multiplying it with the given matrix.
     * This will both rotate and translate the vector p.
     * Assumes the matrix m doesn't contain any perspective projection.
     */
    static transformPoint(p: Vec3Like, matrix: Mat4): Vec3;
    /**
     * Returns a new vector with the given vector transforms as a vector.
     *
     * Transforms the vector as a vector by multiplying it with the given matrix.
     * This will only rotate the vector. The translation part of the matrix will be ignored.
     * Assumes the matrix m doesn't contain any perspective projection.
     */
    static transformVector(p: Vec3Like, matrix: Mat4): Vec3;
    /**
     * Creates a new Vec3 instance from any object with x, y and z properties.
     */
    static from(vec: Vec3Like): Vec3;
    /**
     * Creates a new Vec3 instance from the first 3 elements of the given array.
     */
    static fromArray(arr: ArrayLike<number>): Vec3;
}

/** @module cee */ /** */
/**
 * A View represents a viewport where you can show models and overlay items.
 *
 * A view has a collection of models that are shown in the view. You add a model to a view
 * with the {@link addModel} function and remove it with the {@link removeModel} function.
 *
 * You can access the {@link Camera} from the View with the {@link camera} property. The camera can be
 * used to manually control the view point, projection and other view related settings.
 *
 * A viewer can have one or more views. The views can operate independently or be set up for synchronized viewing.
 * Changes to a model object shared between multiple views will be reflected in all views.
 * The `MultipleViews` example project shows how you can create, manage, and synchronize multiple views.
 *
 * You can manage overlay items (legends, text boxes, navigation cube, etc) with the {@link overlay} object.
 */
export class View {
    /**
     *
    */
    private constructor();
    /**
     * The name of the view (used for debugging)
     */
    get name(): string;
    /**
     *
     */
    set name(name: string);
    /**
     * The owner {@link Viewer}.
     *
     * A View can only be in one Viewer. The Viewer creates and manages the View.
     */
    get ownerViewer(): Viewer;
    /**
     * The 2d overlay controller for the view.
     */
    get overlay(): Overlay;
    /**
     * The {@link Camera} used in the View.
     *
     * The camera can be used to specify the View's viewpoint, orientation, direction, projection, clipping,
     * and other viewport related properties.
     *
     * **Note**:
     *
     * This returns a reference to the real object, not a copy, so any changes to the returned object will be applied
     * to the 3D view.
     */
    get camera(): Camera;
    /**
     * The clipping controller for the view
     */
    get clipping(): Clipping;
    /**
     * The navigation controller for the view.
     */
    /** @deprecated */
    get navigation(): Navigation;
    /**
     * The operator stack for the view.
     */
    get operators(): OperatorStack;
    /**
     * The background config of the view
     */
    get background(): Background;
    /**
     * The ambient occlusion configuration object for the view
     */
    get ambientOcclusion(): AmbientOcclusion;
    /**
     * The amount to dim the areas of the screen that does not contain highlighted parts.
     * Default value is 0.5. Setting a value of 0 disables dimming.
     */
    get nonHighlightedDimFactor(): number;
    /**
     *
     */
    set nonHighlightedDimFactor(factor: number);
    /**
     * The color used to draw the halo around highlighted parts in the view.
     */
    get haloHighlightColor(): Color3Like;
    /**
     *
     */
    set haloHighlightColor(highlightColor: Color3Like);
    /**
     * The number of models in the view.
     */
    get modelCount(): number;
    /**
     * Returns a read only array with all models in the view
     */
    getModelArray(): ReadonlyArray<Model>;
    /**
     * Adds a model to the view.
     *
     * While a model can be shown in any number of views, it can only be added to a particular view once.
     */
    addModel(model: Model): void;
    /**
     * Removes the model at the given index from the view.
     *
     * The index must be zero-based and between 0 and modelCount - 1
     */
    removeModelAt(modelIndex: number): void;
    /**
     * Removes the given model from the view.
     */
    removeModel(model: Model): void;
    /**
     * Removes all models from the view.
     */
    removeAllModels(): void;
    /**
     * Returns the zero-based index of the given model
     */
    getIndexOfModel(model: Model): number;
    /**
     * Returns the model at the given zero-based index
     */
    getModelAt(index: number): Model;
    /**
     * Returns the combined bounding box of all models in the view
     *
     * See {@link Model.getBoundingBox} and {@link ModelBoundingBoxOptions} for more information on how
     * the bounding box is calculated and what options are available.
     */
    getBoundingBox(modelBoundingBoxOptions?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Requests a redraw of the viewer. This will force a redraw on the next
     * {@link CloudSession.handleAnimationFrameCallback} event.
     */
    requestRedraw(): void;
    /**
     * Do a ray intersect with all the models in the view.
     *
     * Returns the intersection point if there was a hit, and null if there was not a hit.
     *
     * Labels have a "special treatment" ray intersect where hitting the label will cause a hit on the label attachment point.
     * This is not always what is intended, e.g. when doing zoom to cursor. Set ignoreLabels to true to skip
     * labels when doing ray intersect. This only applies to PartLabels in the MarkupModel
     */
    rayIntersect(ray: Ray, ignoreLabels?: boolean): Vec3 | null;
    /**
     * Returns a ray that intersects the given point (in world coordinates) and starts at the
     * point's projection onto the screen.
     *
     * Returns null if no ray can be found.
     */
    getRayThroughPoint(point: Vec3): Ray | null;
    /**
     * Sets the viewport to the given position and size in OpenGL window coordinates.
     *
     * This method cannot be called when {@link ownerViewer}.{@link Viewer.viewLayoutMode viewLayoutMode} is set to {@link ViewLayoutMode.Auto}.
     */
    setViewport(x: number, y: number, width: number, height: number): void;
}

/**
 * Defines the method used to determine the position and size of {@link View Views} within a {@link Viewer}.
 *
 * Defaults to Auto.
 */
export enum ViewLayoutMode {
    /**
     * The view layout is set automatically as views are added to the viewer. The first view is positioned on the left side, and subsequent
     * views are stacked on the right side.
     *
     * Any calls to {@link View.setViewport} will throw an error while this mode is active.
     */
    Auto = 0,
    /**
     * The view layout is set manually by calling {@link View.setViewport} on each view. Note that a view will be invisible if no call to {@link View.setViewport} is made.
     */
    Absolute = 1
}
/**
 * The Viewer manages the {@link View Views} it contains and handles user interaction (navigation and picking).
 *
 * You can add a new view with the {@link addView} function. The Viewer owns and manages the
 * View, and you delete the view by using the {@link deleteViewAt} function.
 *
 * A Viewer can have multiple views. A single model can be shared in each view, or multiple different models
 * can be added to specific views. By default, the views are positioned automatically, but you can set the position and size
 * of each view manually using the {@link ViewLayoutMode} accessor.
 *
 * The Viewer handles the interaction with the user, both navigation (pan/rotate/zoom/walk) and
 * selection/picking.
 *
 * You can trigger a redraw of the 3D view(s) with the {@link requestRedraw} function.
 *
 * Examples of the different highlight modes (See {@link ViewerOptions.highlightMode} )
 *
 * ![](/images/HighlightMode.png)
 */
export class Viewer {
    /**
     *
    */
    private constructor();
    /**
     * The current pixel scale factor ( > 1 for 'retina'/'high-dpi') screen.
     */
    get pixelScaleFactor(): number;
    /**
     * The number of views in the Viewer
     */
    get viewCount(): number;
    /**
     * Returns a read only array with all views in the viewer
     */
    getViewArray(): ReadonlyArray<View>;
    /**
     * The view layout mode for the viewer
     */
    get viewLayoutMode(): ViewLayoutMode;
    /**
     *
     */
    set viewLayoutMode(layoutMode: ViewLayoutMode);
    /**
     * Adds a view to the viewer.
     *
     * This functions creates a view, adds it to the viewer and returns the newly created view.
     *
     * You need at least one view in a viewer in order to display a model.
     */
    addView(): View;
    /**
     * Returns the view at the given index.
     *
     * The index must be zero-based and between 0 and viewCount - 1
     */
    getViewAt(viewIndex: number): View;
    /**
     * Deletes the view at the given index.
     *
     * The index must be zero-based and between 0 and viewCount - 1
     */
    deleteViewAt(viewIndex: number): void;
    /**
     * Deletes all views from the viewer.
     */
    deleteAllViews(): void;
    /**
     * Sets the display size of the viewer's canvas in CSS pixels.
     *
     * Note that the input width and height is in CSS pixels which. This means that the resulting size of the
     * canvas in physical pixels may end up being larger than the specified size depending on the currently
     * set pixel scale factor (devicePixelRatio)
     */
    resizeViewer(canvasDisplayWidthCSSPixels: number, canvasDisplayHeightCSSPixels: number): void;
    /**
     * Update the current pixel scale factor by querying {@link window.devicePixelRatio}.
     */
    updatePixelScaleFactor(): void;
    /**
     * Set pixel scale factor.
     */
    setPixelScaleFactor(pixelScaleFactor: number): void;
    /**
     * Notifies that this viewer needs a redraw. This will schedule a redraw on the next timer event.
     *
     * Use this method to force a redraw if you have changed something that does not update the viewer.
     * This is not usually needed.
     */
    requestRedraw(): void;
    /**
     * Flies the camera from the current position to the specified new position in the given view.
     *
     * If the current projection in the active View camera is perspective,
     * the fieldOfViewYDegOrFrontPlaneFrustumHight parameter is the final field of view in Y direction in degrees
     * (as passed to Camera.setProjectionAsPerspective()).
     *
     * If the current projection is ortho, the fieldOfViewYDegOrFrontPlaneFrustumHight parameter is the final
     * front plane frustum height (as passed to Camera.setProjectionAsOrtho()).
     *
     * If view is not specified then the operation is performed on the first view.
     */
    flyCameraTo(cameraPos: Vec3Like, viewDir: Vec3Like, upVec: Vec3Like, fieldOfViewYDegOrFrontPlaneFrustumHight: number, animDuration: number, view?: View): void;
    /**
     * Sets a camera animation that will be run for this viewer
     */
    setCameraAnimation(cameraAnimation: CameraAnimation | null): void;
    /**
     * Sets the handler function to be called whenever the user does a "clean click" in the 3D view.
     *
     * No picking is performed before the given handler is invoked, so the behavior of the click
     * is entirely up to the user.
     *
     * See {@link PickHandler} for more info.
     */
    /** @deprecated */
    setPickHandler(pickHandler: PickHandler): void;
    /**
     * Sets the handler function to be called whenever the user clicks on a color legend.
     *
     * The handler function will be passed the id of the scalar result.
     */
    setColorLegendClickHandler(legendClickHandler: ColorLegendClickedHandler): void;
    /**
     * Sets the handler function to be called whenever the mouse navigation type changes.
     */
    /** @deprecated */
    setActiveMouseNavigationsChangedHandler(navigationHandler: MouseNavigationChangedHandler): void;
    /**
     * Sets the handler function to be called whenever the mouse navigation type changes.
     */
    /** @deprecated */
    enableNavigationHandling(enable: boolean): void;
    /**
     * Mouse tracking needs to be enabled to use the {@link NavigationConfig.leftAndRightMouseButtons} setting.
     *
     * However, for the mouse tracking to work, the browser context menu needs to be disabled.
     *
     * Here is one example on how to do this:
     *
     * ```
     * // Disable context menu - Required for enableMouseButtonTracking
     * canvas.addEventListener("contextmenu", (event) => { event.preventDefault()});
     *
     * // Enable mouse tracking (so we can use leftAndRightMouseButtons)
     * viewer.enableMouseButtonTracking(true);
     *
     * // Envision style navigation
     * const navConfig = view.navigation.config;
     * navConfig.leftMouseButton.noModifier =cee.NavigationType.PAN;
     * navConfig.rightMouseButton.noModifier =cee.NavigationType.ROTATE;
     * navConfig.leftAndRightMouseButtons.noModifier =cee.NavigationType.WALK;
     * navConfig.wheelOrPinch = cee.NavigationType.WALK;
     * ```
     */
    /** @deprecated */
    enableMouseButtonTracking(enable: boolean): void;
    /**
     * Get a ray from the given Canvas/Viewer local CSS coordinate. This coordinate
     * is relative to the top left corner of the canvas/viewer element in css pixels.
     *
     * @param cssPixCoordX The x coordinate in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param cssPixCoordY The y coordinate in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @returns A Ray than can be used for rayIntersect() on the various models. Returns null if
*               a ray could not be created.
     *
     * The input coordinates can be set from MouseEvent.offsetX/offsetY.
     */
    rayFromCssCoordinate(view: View, cssPixCoordX: number, cssPixCoordY: number): Ray | null;
    /**
     * Get the view containing the given Canvas/Viewer local CSS coordinate. This coordinate
     * is relative to the top left corner of the canvas/viewer element in css pixels.
     *
     * The input coordinates can be set from MouseEvent.offsetX/offsetY.
     *
     * @param offsetX The x coordinate in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param offsetY The y coordinate in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @returns The View containing the given coordinate, or null if no view contains the coordinate.
     *
     */
    getViewFromCssCoordinate(offsetX: number, offsetY: number): View | null;
    /**
     * Zooms in or out in the view by the given rubber band rectangle.
     *
     * clientX and clientY are the Top Left corner of the rectangle, specified in client coordinates
     * (HTML window coordinates) (from e.g. a MouseEvent.clientX/Y)
     *
     * NOTE: This is the only method using client coordinates. All other relevant methods use
     * Canvas/Viewer local CSS coordinates. This behavior will change in an upcoming major release.
     */
    rubberBandZoom(view: View, clientX: number, clientY: number, width: number, height: number): void;
    /**
     * Disable the context menu on right click
     */
    get disableContextMenu(): boolean;
    set disableContextMenu(disable: boolean);
    /**
     * Convert from client (DOM content) coordinates to WebGL style coordinates
     *
     * @param clientX The X coordinate of the mouse pointer in local (DOM content) coordinates.
     * @param clientY The Y coordinate of the mouse pointer in local (DOM content) coordinates.
     * @returns The WebGL style <x,y> coordinate for the given client coordinate in the viewer.
     */
    oglWinPosFromClientCoord(clientX: number, clientY: number): Vec2;
    /**
     * Convert from canvas local css (DOM content) coordinates to WebGL style coordinates, similar to
     * offsetX/Y in in MouseEvent.
     *
     * The cssX/Y coordinates local Canvas coordinates in css (DOM content) coordinates. They are
     * local to the Canvas element, so 0,0 is the top left corner of the Canvas element.
     * The coordinates are in css pixels, so they are  not affected by the device pixel ratio or
     * any zoom in the browser. These coordinates are related to the MouseEvent.offsetX/Y coordinates.
     *
     * See https://developer.mozilla.org/en-US/docs/Web/CSS/CSSOM_View/Coordinate_systems for more on
     * CSS coordinate systems. They correspond to the "Offset" system.
     *
     * @param cssPixCoordX The x coordinate in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param cssPixCoordY The y coordinate in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @returns The WebGL style <x,y> coordinate for the given css coordinate in the viewer.
     */
    oglWinPosFromCssCoordinate(cssPixCoordX: number, cssPixCoordY: number): Vec2;
    /**
     * Specifies if the debug overlay info window should be shown or not
     */
    setShowDebugWindow(show: boolean): void;
}
/**
 * Describes the state of the modifier keys.
 */
export class KeyboardModifiers {
    /**
     * Whether the shift key is pressed.
     */
    shift: boolean;
    /**
     * Whether the control key is pressed.
     */
    control: boolean;
    /**
     * Whether the alt key is pressed.
     */
    alt: boolean;
    /**
     * Whether the meta key is pressed.
     */
    meta: boolean;
}
/**
 * Object containing pick handler data, used in the {@link PickHandler}
 */
export interface PickHandlerData {
    /**
     * The {@link View} the picking was performed in.
     */
    view: View;
    /**
     * The state of the modifier keys while the picking was performed.
     */
    modifiers: KeyboardModifiers;
    /**
     * The {@link Ray} defined by position and direction in world coordinates.
     */
    ray: Ray;
}
/**
 * Defines the signature of PickHandlers, which are called by the viewer when the user performs a picking action.
 *
 * The picking action is defined as a clean click with the left mouse button or a clean touch.
 * In this handler you should determine whether to perform picking on the remote model (using the
 * {@link cee.ug!RemoteModel.rayIntersect ug.RemoteModel.rayIntersect} function, by far the most common action)
 * or to perform any other action.
 *
 * When the picking is done the callback passed to the rayIntersect() function will be called.
 * In this function you can determine what to do with the result. The possibilities include:
 *
 * - Highlighting the element
 * - Showing picking info in a dialog
 * - Adding an annotation
 * - Positioning a cutting plane
 * - Adding a seed point for a particle trace
 * - etc...
 */
export interface PickHandler {
    /**
     *
     *
     *
     */
    (pickHandlerData: PickHandlerData): void;
}
/**
 * Defines the signature of ColorLegendClickHandlers, which are invoked when the user clicks on a color legend.
 *
 * The resultId and the containing view index of the scalar associated with the color legend is passed to the handler
 * function. A typical response to this would be to show the settings for this scalar in the UI, or present
 * a context menu letting the user manipulate the scalar/color legend.
 */
export interface ColorLegendClickedHandler {
    /**
     *
     *
     *
     */
    (resultId: number, viewIndex: number): void;
}
/**
 * Defines the signature of MouseNavigationChangedHandler, which are invoked whenever the mouse navigation type changes
 *
 * Useful for updating mouse cursors.
 */
export interface MouseNavigationChangedHandler {
    /**
     *
     *
     *
     */
    (currentNavigationType: NavigationType): void;
}
export interface ClientCoord {
    clientX: number;
    clientY: number;
}
export interface ClientCoordList {
    readonly length: number;
    [index: number]: ClientCoord;
}

/** @module cee */ /** */
/**
 * Modes specifying how to render opaque geometry when using WBOIT
 */
export enum WBOITMode {
    /**
     * Render opaque geometry to default framebuffer, allows usage of antialiased render context
     */
    OPAQUE_DEFAULT_FRAMEBUFFER = 0,
    /**
     * Render opaque geometry to off-screen buffer
     */
    OPAQUE_OFFSCREEN = 1
}
/**
 * Modes specifying how to render the highlighted parts from the models in the view.
 *
 * **Examples of the different highlight modes:**
 *
 * ![](/images/HighlightMode.png)
 */
export enum HighlightMode {
    /**
     * Disable halo/silhouette highlighting. Highlight setting is ignored.
     */
    OFF = 0,
    /**
     * Simple halo highlighting, drawing a halo around the silhouette of the part
     */
    SIMPLE = 1,
    /**
     * Draw a halo around the silhouette of the part. The parts of the halo that is obscured by parts of the model
     * will be dimmed down. Parts not being highlighted will also be dimmed down depending on the
     * {@link View.nonHighlightedDimFactor} setting.
     */
    DEPTH_BASED_DIMMING = 2
}
/**
 * Rendering options for a {@link Viewer}
 *
 * **Examples of the different highlight modes:**
 *
 * ![](/images/HighlightMode.png)
 */
export class ViewerOptions {
    /**
     * Whether to enable high quality transparency using a technique called "Weighted Blended Order-Independent Transparency"
     */
    enableTransparencyWBOIT?: boolean;
    /**
     * Specify how to render opaque parts when there are transparent parts in the scene and
     *  enableTransparencyWBOIT is enabled.
     */
    wboitMode?: WBOITMode;
    /**
     * Whether to enable highlighting of parts using a halo
     */
    highlightMode?: HighlightMode;
    /**
     * Specify the global default specular intensity
     */
    globalDefaultSpecularIntensity?: number;
    /**
     * Specify the global ambient intensity
     */
    globalAmbientIntensity?: number;
    /**
     * Use anti aliasing. Default true
     */
    antiAliasing?: boolean;
    /**
     * If true, the drawing buffer will have an alpha channel which can be useful for compositing with the page
     * or for retrieving transparent image snapshots. Default false
     */
    alphaChannel?: boolean;
    /**
     * preserveDrawingBuffer
     */
    preserveDrawingBuffer?: boolean;
    /**
     * This option can be used to force usage of WebGL 1 instead of WebGL2. Default false
     */
    forceWebGL1?: boolean;
    /**
     * This option enable the use of Operators for input handling and UI
     */
    useOperators?: boolean;
}


//
// geo
// ===================================================================================
export namespace geo {

/** @module cee.geo */ /** */
/**
 * Helper class for creating a Model from a .cgeo blob.
 *
 * The .cgeo blob is typically received from a web service or a local file.
 *
 * Usage:
 * ```javascript
 * let geoModel = new cee.geo.GeometryModel();
 * let modelGenerator = new cee.geo.CgeoModelGenerator(buffer, geoModel);
 * modelGenerator.buildModel();
 * ```
 *
 * ** CGEO format documentation **
 *
 *```
 * Int     Magic Number (2072003)
 * Int     TextureCount
 * Int     PartCount
 *
 * Textures (TextureCount number of this block):
 *      Int Index : Zero based index
 *      Int Width : Width of texture in pixels (see note below about dimensions)
 *      Int Height : Height of texture in pixels (see note below about dimensions)
 *      Int WrapMode : 1: Clamp To Edge, 2: Repeat
 *      Int MinFilter : 1: Nearest, 2: Linear, 3: Nearest Mipmap Nearest,
 *                      4: Nearest Mipmap Linear, 5: Linear Mipmap Nearest,
 *                      6: Linear Mipmap Linear
 *      Int MagFilter : 1: Nearest, 2: Linear
 *      ubyte\*Width\*Height  pixelData : First pixel is lower left corner
 *
 * Parts (PartCount number of this block):
 *      Int     PartId
 *      Int     Color (r,g,b,a)
 *      Int     NumVertices
 *      Int     HasNormals (1=true, 0=false)
 *      Int     TextureIndex (-1 for none)
 *      Int     NumPrimitives
 *      Int     VerticesPerPrimitive
 *
 *      Vertices:
 *        3*float     vertex x,y,z
 *
 *      Normals:
 *        3*float     vertex nx,ny,nz
 *
 *      TextureCoordinates:
 *        2*float     vertex s,t
 *
 *      Indices:
 *        <NumPrimitives*VerticesPerPrimitive>
 *
 * ```
 *
 * **Notes:**
 *
 * Texture dimensions: Generally we recommend using textures where the dimensions (height and width) are a power of two (2,4,8,16, etc).
 * Non-POT2 texture are partially supported in WebGL, but requires the sampler to be configured without MipMaps and with wrap mode set to
 * ClampToEdge.
 *
 * Color is r,g,b,a packet into one integer. Example with float colors (0..1 per component):
 *
 *         int intOpacity = (int)(opacity*255.0f);
 *         int intColor = (int)(color.r()*255.0f)<<24 | (int)(color.g()*255.0f)<<16 | (int)(color.b()*255.0f)<<8 | intOpacity;
 *
 */
export class CgeoModelGenerator {
    /**
     * Creates a new CgeoModelGenerator with the given input Cgeo array and output geometry model
     */
    constructor(cgeoBuffer: ArrayBuffer, geoModel: GeometryModel);
    /**
     * Adds parts to the input GeometryModel based on the content of the Cgeo array
     */
    buildModel(preserveSharpEdges?: boolean): void;
}

/** @module cee.geo */ /** */
/**
 * HitItem contains the result of a picking operation (`rayIntersect()`) on a GeometryModel.
 */
export interface HitItem {
    /**
     * The index of the part within the GeometryModel
     */
    partIndex: number;
    /**
     * The index of the primitive within the part's Mesh
     */
    primitiveIndex: number;
    /**
     * The 3d point (in world coordinates) of the intersection between the ray and the primitive that was hit
     */
    intersectionPoint: Vec3;
}

/** @module cee.geo */ /** */
/**
 * Enum specifying the primitive type (TRIANGLES, LINES).
 *
 * Used by Mesh and its implementers to define the type of primitives contained in the Mesh
 */
export enum MeshPrimitiveType {
    /** Lines */
    LINES = 2,
    /** Triangles */
    TRIANGLES = 3
}
/**
 * A Mesh defines the geometry (primitives) of a Part.
 *
 * Common interface for all Mesh classes.
 */
export interface Mesh {
    /**
     * The type of primitives that are used in the mesh.
     */
    readonly primitiveType: MeshPrimitiveType;
    /**
     * The number of primitives in the mesh.
     */
    readonly primitiveCount: number;
    /**
     * The number of vertices in the mesh.
     */
    readonly vertexCount: number;
    /**
     * The {@link BoundingBox} of the mesh.
     */
    readonly boundingBox: BoundingBox;
    /**
     * Returns the vertex indices of a given primitive.
     */
    getPrimitiveVertices(primitiveIndex: number): Vec3[];
    /**
     * Performs picking on the mesh.
     */
    rayIntersect(ray: Ray, hitItem?: MeshHitItem): boolean;
}

/** @module cee.geo */ /** */
/**
 * MeshHitItem contains the result of a picking operation (`rayIntersect()`) on a Mesh.
 */
export class MeshHitItem {
    /**
     * The index of the primitive that was hit.
     */
    primitiveIndex: number;
    /**
     * The intersection point.
     */
    intersectionPoint: Vec3 | null;
}

/** @module cee.geo */ /** */
export interface OptionalIndexedLinesVertexData {
    textureCoordinates?: ArrayLike<number>;
}
/**
 * This class implements a {@link Mesh} for indexed lines.
 *
 * Rather than defining each line directly as an array of vertices, an array containing each
 * unique vertex in the part is defined. Then lines are defined by arrays of indices that refer to
 * elements of this vertex array. This allows lines to share vertices, thus reducing the number of
 * vertices.
 */
export class MeshIndexedLines implements Mesh {
    /**
     * Creates an indexed lines mesh with the given vertices and indices.
     */
    constructor(vertices: ArrayLike<number>, indices: ArrayLike<number>, optionalVertexData?: OptionalIndexedLinesVertexData);
    /**
     * The type of primitives that are used in the mesh.
     */
    get primitiveType(): MeshPrimitiveType;
    /**
     * The number of primitives in the mesh.
     */
    get primitiveCount(): number;
    /**
     * The number of vertices in the mesh.
     */
    get vertexCount(): number;
    /**
     * Returns a copy of the {@link BoundingBox} of the mesh
     */
    get boundingBox(): BoundingBox;
    /**
     * A readonly array containing the vertices of the mesh
     */
    get vertexArray(): ArrayLike<number>;
    /**
     * A readonly array containing the indices of the mesh
     */
    get indexArray(): ArrayLike<number>;
    /**
     * A readonly array containing the 2d texture coordinates of the mesh
     */
    get textureCoordinates(): ArrayLike<number> | null;
    /**
     * Returns a copy of the vertex indices of a given primitive.
     */
    getPrimitiveVertices(primitiveIndex: number): Vec3[];
    /**
     * Performs picking on the mesh.
     *
     * If a primitive was hit, the function returns true and populates the passed hitItem object with
     * information about this primitive. It nothing was hit, returns false.
     */
    rayIntersect(ray: Ray, hitItem?: MeshHitItem): boolean;
}

/** @module cee.geo */ /** */
export interface OptionalIndexedTriangleVertexData {
    vertexNormals?: ArrayLike<number>;
    textureCoordinates?: ArrayLike<number>;
}
/**
 * This class implements a {@link Mesh} for indexed triangles.
 *
 * Rather than defining each triangle directly as an array of vertices, an array containing x, y and z values for each
 * unique vertex in the part is defined. Then triangles are defined by arrays of indices that refer to
 * elements of this vertex array. This allows triangles to share vertices, thus reducing the number of
 * vertices, and enabling the computation of smooth shade normals.
 *
 * Note that while the vertices array contains 3 elements per point (x, y and z), the elements in the indices array are
 * interpreted as vertex indices. For example, if vertices contains 3 vertices A, B and C:
 *
 * ````
 * vertices = [Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz];
 * ````
 *
 * Then vertex A is at index 0, vertex B and 1 and vertex C at 2. So the triangle containing these vertices would be defined
 * with
 *
 * ````
 * indices = [0, 1, 2];
 * ````
 */
export class MeshIndexedTriangles implements Mesh {
    /**
     * Creates an indexed triangle mesh with the given vertices and indices.
     */
    constructor(vertices: ArrayLike<number>, indices: ArrayLike<number>, optionalVertexData?: OptionalIndexedTriangleVertexData | null);
    /**
     * Creates an indexed triangle mesh with the given vertices and indices.
     *
     * Preserve sharp edges by splitting vertices on edges where the surface normal of the two triangles
     * sharing the edge is more than the given angle (in degrees).
     */
    static constructPreserveSharpEdges(creaseAngleDegrees: number, vertices: ArrayLike<number>, indices: ArrayLike<number>, optionalVertexData?: OptionalIndexedTriangleVertexData): MeshIndexedTriangles;
    /**
     * The type of primitives that are used in the mesh.
     */
    get primitiveType(): MeshPrimitiveType;
    /**
     * The number of primitives in the mesh.
     */
    get primitiveCount(): number;
    /**
     * The number of vertices in the mesh.
     */
    get vertexCount(): number;
    /**
     * Returns a copy of the {@link BoundingBox} of the mesh
     */
    get boundingBox(): BoundingBox;
    /**
     * A readonly array containing the vertices of the mesh
     */
    get vertexArray(): ArrayLike<number>;
    /**
     * A readonly array containing the indices of the mesh
     */
    get indexArray(): ArrayLike<number>;
    /**
     * A readonly array containing the 2d texture coordinates of the mesh
     */
    get textureCoordinates(): ArrayLike<number> | null;
    /**
     * Returns a copy of the vertex indices of a given primitive.
     */
    getPrimitiveVertices(primitiveIndex: number): Vec3[];
    /**
     * Performs picking on the mesh.
     *
     * If a primitive was hit, the function returns true and populates the passed hitItem object with
     * information about this primitive. It nothing was hit, returns false.
     */
    rayIntersect(ray: Ray, hitItem?: MeshHitItem): boolean;
}

/** @module cee.geo */ /** */
/**
 * The {@link GeometryModel} implements a client-side model that can handle a large number of parts efficiently.
 *
 * The model can be created and modified in the client application and is not dependent on a server (unlike
 * ug.RemoteModel).
 *
 * Each view can contain many {@link GeometryModel GeometryModels}. A {@link GeometryModel} is a collection of parts. Each {@link Part} is defined
 * by its {@link Mesh}, which describes the triangles, lines and points, and by its PartSettings, which specify how the part
 * is rendered.
 *
 * A {@link GeometryModel} can have a transformation matrix ({@link transformationMatrix}) useful for scene composition
 * or for doing rigid body animations.
 *
 * Picking is supported via {@link rayIntersect} which returns a {@link HitItem} containing the intersection point, part index
 * and primitive index within that part, and {@link regionIntersect} which returns an array of parts (partially) within
 * a given rectangle in screen coordinates.
 *
 * See the example in Examples/BuildYourFirstApp/1-HelloEnvision for how to use the {@link GeometryModel}.
 *
 * Here is a simple example that creates a geometry model with one part and one triangle and adds it to the current view:
 * ```javascript
 * var geoModel = new cee.geo.GeometryModel();
 *
 * // Create a simple one triangle one part model
 * var indices = [0, 1, 2];
 * var triangleVertices = [0,0,0,  1,0,0,  0,1,0];
 *
 * let part = geoModel.addPart();
 * let mesh = new cee.geo.MeshIndexedTriangles(triangleVertices, indices);
 * part.mesh = mesh;
 *
 * part.settings.color = new cee.Color3(0, 1, 0);
 *
 * var view = myViewer.getViewAt(0);
 * view.addModel(geoModel);
 * view.requestRedraw();
 * ```
 */
export class GeometryModel extends Model {
    /**
     * Constructor
     */
    constructor();
    /**
     * The name of the geometry model. Mainly used for debugging.
     */
    get name(): string;
    /**
     *
     */
    set name(name: string);
    /**
     * The transformation matrix to use for this model.
     *
     * If specified, all parts in the model will be transformed by this matrix. This can be useful for scene
     * composition and for rigid body type animations. The default is null.
     */
    get transformationMatrix(): Mat4 | null;
    /**
     *
     *
    */
    set transformationMatrix(transformationMatrix: Mat4 | null);
    /**
     * Enable or disable option to ignore view clipping in this model
     */
    get ignoreViewClipping(): boolean;
    set ignoreViewClipping(ignore: boolean);
    /**
     * The number of parts in the model.
     */
    get partCount(): number;
    /**
     * Returns a read only array with all parts
     */
    getPartArray(): ReadonlyArray<Part>;
    /**
     * Creates a new part and adds it to the model.
     *
     * Returns the newly created part.
     */
    addPart(): Part;
    /**
     * Returns an active reference to the part at the given (zero based) index.
     */
    getPartAt(partIndex: number): Part;
    /**
     * Deletes the part at the given (zero based) index.
     */
    deletePartAt(partIndex: number): void;
    /**
     * Deletes the parts at the given indices.
     */
    deletePartsAt(partIndicesArr: number[]): void;
    /**
     * Deletes all parts in model
     */
    deleteAllParts(): void;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the model.
     *
     * By default, the returned bounding box will only include visible parts.
     * If you want the bounding box to include all parts, regardless of visibility, set
     * the {@link ModelBoundingBoxOptions.includeHiddenParts} option to true.
     * Please note that there might be a significant performance penalty for including hidden parts.
     */
    getBoundingBox(options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns default camera configuration, which is always null for this model.
     */
    getDefaultCameraConfig(): null;
    /**
     * Performs picking on the model.
     *
     * If something was hit, returns a HitItem containing information about the part and primitive that was hit.
     *
     * If nothing was hit, returns null.
     */
    rayIntersect(ray: Ray): HitItem | null;
    /**
     * Sets the color of the parts in the model based on the given scalarMapper and a scalar per part.
     *
     * This is useful for showing per-part scalar results on a GeometryModel.
     *
     * To show a color legend representing the scalar mapper in a View, use the
     * View.overlay.addCustomColorLegendForScalarMapper() method.
     *
     * This method is just a helper for doing the following:
     * ```javascript
     * const partCount = this.partCount;
     * for (let i = 0; i < partCount; ++i) {
     *     let color = scalarMapper.mapToColor(perPartResult[i]);
     *     let part = this.getPartAt(i);
     *     part.settings.color = color.toColor3();
     *     part.settings.opacity = color.a;
     * }
     * ```
     */
    setColorPerPartFromMapper(scalarMapper: ScalarMapper, perPartResult: ArrayLike<number>): void;
    /**
     * Returns the parts that are (partially) inside the given region.
     *
     * The returned list of parts will contain all parts that are inside the given region. If acceptPartiallyContainedParts
     * is set to true, parts will be considered inside if they are partially (at least one of the vertices) inside
     * the region. If false, the entire part needs to be completely inside the region.
     *
     * Please note that this method works at the vertex level. This means that for a part to be considered
     * partially inside the region, at least one of its vertices must be within the specified region.
     * If acceptPartiallyContainedParts is set to false, all vertices must be inside the region.
     * If this method is used in combination with view clipping planes, only vertices that are visible with
     * regards to the specified clipping planes will be considered.
     *
     * The x and y coordinates must be specified in OpenGL style coordinates, which means a right handed coordinate system
     * with the origin in the lower left corner of the window. The HTML coordinate system is with origin in top left,
     * so if this is your input (e.g. MouseEvent.offsetY, clientY, pageY, etc.) you will have to flip the Y coordinate.
     * The x and y are specified in native pixels, so you will have to adjust the input for the current devicePixelRatio
     * (window.devicePixelRatio).
     *
     * The width and height are specified in native pixels. So you will have to adjust the input for the current devicePixelRatio
     * (window.devicePixelRatio).
     *
     * NOTE: This is the only method using OpenGL/WebGL style coordinates. All other relevant methods use
     * Canvas/Viewer local CSS coordinates. This behavior will change in an upcoming major release.
     *
     * **Example:** Change the color of all parts within the rectangle defined by a rubber band
     *
     *```javascript
     *
     * // this.m_startX/this.m_startY is the event.offsetX/event.offsetY at the
     * // start of the region definition
     * endRegionSelection(event: MouseEvent) {
     *     this.m_regionSelectActive = false;
     *
     *     let pixelScaleFactor = window.devicePixelRatio || 1;
     *     let startXPixels = this.m_startX * pixelScaleFactor;
     *     let startYPixels = this.m_startY * pixelScaleFactor;
     *     let endXPixels = event.offsetX * pixelScaleFactor;
     *     let endYPixels = event.offsetY * pixelScaleFactor;
     *
     *     // Note: Canvas height is in native pixels, so no scaling with pixelScaleFactor
     *     let canvasHeightPixels = this.m_canvas.height;
     *
     *     let leftPixels = Math.min(startXPixels, endXPixels);
     *     let rightPixels = Math.max(startXPixels, endXPixels);
     *     let topPixels = Math.max(canvasHeightPixels - startYPixels,
     *                              canvasHeightPixels - endYPixels);
     *     let bottomPixels = Math.min(canvasHeightPixels - startYPixels,
     *                              canvasHeightPixels - endYPixels);
     *     let widthPixels = (rightPixels - leftPixels);
     *     let heightPixels = (topPixels - bottomPixels);
     *
     *     let parts = this.m_model.regionIntersect(leftPixels, bottomPixels,
     *                                   widthPixels, heightPixels, this.m_view, true);
     *
     *     let selectColor = new cee.Color3(1,0,1);
     *     for(let part of parts) {
     *         part.settings.color = selectColor;
     *     }
     *
     *     this.m_regionSelectionDiv.hidden = true;
     * }
     *```
     */
    regionIntersect(x: number, y: number, width: number, height: number, view: View, acceptPartiallyContainedParts: boolean): Part[];
}

/** @module cee.geo */ /** */
/**
 * A GeometryModelManipulator works on a given geometry model to do different tasks.
 *
 */
export class GeometryModelManipulator {
    /**
     * Creates a new GeometryModelManipulator with the given input geometry model
     */
    constructor(geoModel: GeometryModel);
    /**
     * Creates a cross section geometry model
     *
     * Creates a new geometry model where the given plane intersects with the given input geometry model.
     * Intersected triangles will be represented as lines.
     * Part attributes will be preserved, where possible.
     * The customData attribute in the new part is set to the index of the original part.
     * Also includes invisible parts, if any.
     * Coplanar triangles will be represented as lines forming the contour of the coplanar area.
     *
     * Returns a geometry model with the visible and invisible intersected parts.
     */
    createCrossSectionModel(plane: Plane): GeometryModel;
}

/** @module cee.geo */ /** */
/**
 * Helper class for creating simple geometry models
 */
export class GeometryModelMockups {
    /**
     * Populates the model with the given number of parts, with each part consisting of a single triangle.
     */
    static populateModelWithSingleTriangleParts(model: geo.GeometryModel, numParts: number): void;
    /**
     * Populates the model with the given number of parts, with each part consisting of a textured quad.
     */
    static populateModelWithTexturedQuadParts(model: geo.GeometryModel, numParts: number, texture: Texture): void;
    /**
     * Populates the model with the given number of parts, with each part consisting of a line mesh formed as a square
     */
    static populateModelWithLineSquaresParts(model: geo.GeometryModel, numParts: number): void;
}

/** @module cee.geo */ /** */
export interface RemoteLoaderModelInfo {
    boundingBox: BoundingBox;
}
export class RemoteLoaderStatusInfo {
    totalChunkCount: number;
    receivedChunkCount: number;
    totalPartCount: number;
    receivedPartCount: number;
}
export class RemoteLoaderTimingInfo {
    elapsedTime_ms: number;
}
export interface RemoteLoaderInitializationCompleteCallback {
    (modelInfo: RemoteLoaderModelInfo): void;
}
export interface RemoteLoaderCompleteCallback {
    (error: Error | null): void;
}
/**
 *
 *
 */
export class GeometryModelRemoteLoader {
    /**
     *
     */
    constructor(serverUrl: string);
    /**
     *
     */
    configurePreserveSharpEdges(preserveSharpEdges: boolean): void;
    /**
     *
     */
    configureLowResModel(targetLowResModel: GeometryModel): void;
    /**
     *
     */
    setInitializationCompleteCallback(initializationCompleteCallback?: RemoteLoaderInitializationCompleteCallback): void;
    /**
     *
     */
    loadModel(modelKey: string, targetModel: GeometryModel, loadingCompleteCallback?: RemoteLoaderCompleteCallback): void;
    /**
     *
     */
    cancelLoading(): void;
    /**
     *
     */
    getStatusInfo(): RemoteLoaderStatusInfo;
    /**
     *
     */
    getTimingInfo(): RemoteLoaderTimingInfo;
    /**
     *
     */
    setCamera(camera: Camera): void;
}

/**
 * A Part is a collection of primitives (triangles, lines, points) and a specification of how to
 * render these primitives.
 *
 * The primitives are defined as a Mesh.
 *
 * The PartSettings class defines how a part will be rendered (color, opacity, visibility) and if
 * the part should be intersectable or not.
 *
 * The GeometryModel is designed to handle a large number of parts (at least 300k+ without issues).
 */
export class Part {
    /**
     *
    */
    private constructor();
    /**
     * The mesh defining the geometry of the part. If no mesh is defined, null is returned.
    */
    get mesh(): Mesh | null;
    /**
     *
     */
    set mesh(mesh: Mesh | null);
    /**
     * The transformation matrix to use for this part.
     *
     * The default is null.
     */
    get transformationMatrix(): Mat4 | null;
    set transformationMatrix(transformationMatrix: Mat4 | null);
    /**
     * Returns an active reference to the settings for this part.
     */
    get settings(): PartSettings;
    /**
     * Custom data for the part. This field is not used by EnvisionWeb.
     */
    get customData(): any;
    /**
     *
     */
    set customData(data: any);
    /**
     * The index of the part in the parent geometry model
     */
    get partIndex(): number;
}

/**
 * Polygon offset mode
 */
export enum PolygonOffset {
    /**
     * No eye lift is used (default)
     */
    OFF = 0,
    /**
     * Offset the polygon away from the eye
     */
    ON = 1
}
/**
 * PartSettings defines properties that control how the part is rendered and behaves.
 */
export class PartSettings {
    /**
     *
     */
    private constructor();
    /**
     * The visibility of the part
     */
    get visible(): boolean;
    /**   */
    set visible(visible: boolean);
    /**
     * Whether the part should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
    /**
     * Specifies if the part should be considered by picking (`rayIntersect()`) or not
     */
    get intersectable(): boolean;
    /**  */
    set intersectable(intersectable: boolean);
    /**
     * The color of the part. Note that the returned color cannot be modified.
     */
    get color(): Color3Like;
    /**  */
    set color(color: Color3Like);
    /**
     * The intensity of the specular highlight of the part
     *
     * Note that the part's default value for specularIntensity is undefined in which case the global
     * default specular intensity will be used. Specify this value to override the default setting.
     */
    get specularIntensity(): number | undefined;
    set specularIntensity(intensity: number | undefined);
    /**
     * The opacity of the part.
     *
     * 1.0 is fully opaque, 0.0 is fully transparent (invisible).
     */
    get opacity(): number;
    /**
     *
     *
    */
    set opacity(opacity: number);
    /**
     * The polygon offset mode to use for this part
     */
    get polygonOffset(): PolygonOffset;
    set polygonOffset(mode: PolygonOffset);
    /**
     * The eye lift mode to use for this part
     */
    get eyeLift(): EyeLift;
    set eyeLift(mode: EyeLift);
    /**
     * Texture to use for this part. If no texture is defined, null is returned.
     *
     * Note that using textures requires that the mesh type is MeshIndexedTriangles and that you have
     * specified texture coordinates in the mesh.
     */
    get texture(): Texture | null;
    set texture(texture: Texture | null);
    /**
     * The line width in pixels for line meshes
     *
     * Note that setting the width to values greater than 1, will trigger generation and rendering of thick
     * lines which can significantly reduce update and rendering performance.
     */
    get lineWidth(): number;
    set lineWidth(lineWidth: number);
}

} // geo



//
// mrk
// ===================================================================================
export namespace mrk {

/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link LabelAppearance}
 */
export interface LabelAppearanceProperties {
    fontFamily: string;
    fontSize: number;
    fontStyle: "normal" | "italic" | "oblique";
    fontVariant: "normal" | "small-caps";
    fontWeight: "normal" | "bold" | "lighter" | "bolder";
    textColor: Color3Like;
    backgroundVisible: boolean;
    backgroundColor: Color3Like;
    borderVisible: boolean;
    borderColor: Color3Like;
    borderWidth: number;
    opacity: number;
    cornerRadius: number;
}
/**
 * Appearance settings for text labels
 */
export class LabelAppearance {
    /**
     *
     */
    private constructor();
    /**
     * Font family
     *
     * Corresponds to the CSS font-family property
     */
    get fontFamily(): string;
    set fontFamily(family: string);
    /**
     * Font size in pixels
     */
    get fontSize(): number;
    set fontSize(sizeInPixels: number);
    /**
     * Corresponds to the CSS font-style property
     */
    get fontStyle(): "normal" | "italic" | "oblique";
    set fontStyle(style: "normal" | "italic" | "oblique");
    /**
     * Corresponds to the CSS font-variant property
     */
    get fontVariant(): "normal" | "small-caps";
    set fontVariant(variant: "normal" | "small-caps");
    /**
     * Corresponds to the CSS font-weight property
     */
    get fontWeight(): "normal" | "bold" | "lighter" | "bolder";
    set fontWeight(weight: "normal" | "bold" | "lighter" | "bolder");
    /**
     * The color of the text
     */
    get textColor(): Color3Like;
    set textColor(clr: Color3Like);
    /**
     * Flag that determines if the filled background of the labels should be drawn or not.
     */
    get backgroundVisible(): boolean;
    set backgroundVisible(visible: boolean);
    /**
     * Color of the filled background
     */
    get backgroundColor(): Color3Like;
    set backgroundColor(clr: Color3Like);
    /**
     * Flag that determines if border around the labels should be drawn or not.
     */
    get borderVisible(): boolean;
    set borderVisible(visible: boolean);
    /**
     * Color of the label border
     */
    get borderColor(): Color3Like;
    set borderColor(clr: Color3Like);
    /**
     * Width of the label border in pixels
     */
    get borderWidth(): number;
    set borderWidth(width: number);
    /**
     * The opacity of the label.
     *
     * Setting the opacity will influence the label background and the border, but will not affect the
     * actual label text. Opacity 1.0 is fully opaque, 0.0 if fully transparent (invisible).
     */
    get opacity(): number;
    set opacity(opacity: number);
    /**
     * Radius, in pixels, of rounded corners.
     *
     * Setting a value of 0 disables rounded corners. Default 0
     */
    get cornerRadius(): number;
    set cornerRadius(radiusInPixels: number);
    /**
     * Gets the appearance settings for this labels part as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): LabelAppearanceProperties;
    /**
     * Applies the settings in the given properties object to this appearance object
     */
    setFromProperties(props: Partial<LabelAppearanceProperties>): void;
}

/** @module cee.mrk */ /** */
/**
 * Type of attachment that connects labels to their 3D position
 */
export enum LabelAttachmentType {
    LINE = 0,
    ARROW = 1
}
/**
 * Appearance settings for attachments that connect labels to their 3D position
 */
export class LabelAttachmentAppearance {
    /**
     *
     */
    private constructor();
    /**
     * Type of attachment
     */
    get type(): LabelAttachmentType;
    set type(type: LabelAttachmentType);
    /**
     * Length in pixels of the line that attaches the label to its 3D position
     */
    get lineLength(): number;
    set lineLength(lengthInPixels: number);
    /**
     * The color of the anchor point
     */
    get anchorPointColor(): Color3Like;
    set anchorPointColor(color: Color3Like);
    /**
     * The size of the anchor point in pixels. To disable drawing of the anchor point set the size
     * to zero.
     */
    get anchorPointSize(): number;
    set anchorPointSize(size: number);
    /**
     * Length in pixels of arrow heads
     */
    get arrowHeadLength(): number;
    set arrowHeadLength(arrowHeadLength: number);
    /**
     * Width in pixels of arrow heads
     */
    get arrowHeadWidth(): number;
    set arrowHeadWidth(arrowHeadWidth: number);
}

/** @module cee.mrk */ /** */
/**
 * HitItem contains the result of a picking operation (`rayIntersect()`) on a MarkupModel.
 */
export interface HitItem {
    /**
     * The index of the part within the MarkupModel
     */
    partIndex: number;
    /**
     * The index of the primitive within the Part
     */
    primitiveIndex: number;
    /**
     * The 3d point (in world coordinates) of the intersection between the ray and the primitive that was hit
     */
    intersectionPoint: Vec3;
}
/**
 * HitItem contains the result of a picking operation (`rayIntersect()`) on a MarkupModel part.
 */
export class PartHitItem {
    /**
     * The index of the primitive that was hit.
     */
    primitiveIndex: number;
    /**
     * The intersection point.
     */
    intersectionPoint: Vec3 | null;
}
/**
 * This class can be used to add markup items to a visualization.
 */
export class MarkupModel extends Model {
    /**
     * Constructor
     */
    constructor();
    /**
     * Name of the markup model.
     */
    get name(): string;
    set name(name: string);
    /**
     * Enable or disable option to ignore view clipping in this model
     */
    get ignoreViewClipping(): boolean;
    set ignoreViewClipping(ignore: boolean);
    /**
     * The number of parts in the model.
     */
    get partCount(): number;
    /**
     * Adds a part containing indexed triangles to the markup model. Use the returned {@link PartIndexedTriangles}
     * to set the mesh data and color of the new part.
     */
    addIndexedTrianglesPart(): PartIndexedTriangles;
    /**
     * Adds a part containing textured indexed triangles to the markup model. Use the returned {@link PartTexturedIndexedTriangles}
     * to set the mesh data and texture of the new part.
     */
    addTexturedIndexedTrianglesPart(): PartTexturedIndexedTriangles;
    /**
     * Adds a part for drawing points. Use the returned {@link PartPoints} to add points to the new part.
     */
    addPointsPart(): PartPoints;
    /**
     * Adds a part for drawing lines. Use the returned {@link PartLines} to add lines to the new part.
     */
    addLinesPart(): PartLines;
    /**
     * Adds a part for drawing points. Use the returned {@link PartPoints} to add points to the new part.
     */
    addArrowsPart(): PartArrows;
    /**
     * Adds a part containing positioned text labels to the markup model. Use the returned {@link PartLabels} to add text labels
     * to the new part.
     */
    addLabelsPart(): PartLabels;
    /**
     * Add a part with an image attached to a 3d coordinate
     */
    addImageLabelPart(): PartImageLabel;
    /**
     * Returns an active reference to the part at the given (zero-based) index.
     */
    getPartAt(partIndex: number): Part;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the model.
     *
     * Note that currently this method does not support any {@link ModelBoundingBoxOptions}
     */
    getBoundingBox(_options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns default camera configuration, which is always null for this model.
     */
    getDefaultCameraConfig(): null;
    /**
     * Deletes the part at the given (zero-based) index.
     */
    deletePartAt(partIndex: number): void;
    /**
     * Delete the given part if present.
     *
     * Returns true if the part was found and deleted, false if not.
     */
    deletePart(part: Part): boolean;
    /**
     * Deletes all parts in model
     */
    deleteAllParts(): void;
    /**
     * Performs picking on the model.
     *
     * If something was hit, returns a HitItem containing information about the part and primitive that was hit.
     *
     * If nothing was hit, returns null.
     *
     * Labels have a "special treatment" ray intersect where hitting the label will cause a hit on the label attachment point.
     * This is not always what is intended, e.g. when doing zoom to cursor. Set ignoreLabels to true to skip
     * labels when doing ray intersect.
     */
    rayIntersect(ray: Ray, ignoreLabels?: boolean): HitItem | null;
}

/**
 * Base class for parts that can be added to a {@link MarkupModel}.
 */
export abstract class Part {
    /**
     * Custom data for the part. This field is not used by EnvisionWeb.
     */
    get customData(): any;
    set customData(data: any);
    /**
     * Picking on the part
     */
    abstract rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
}

/** @module cee.mrk */ /** */
/**
 * A part that can show arrows in a {@link MarkupModel}.
 *
 * Use {@link MarkupModel.addArrowsPart} to create a new instance of this class.
 */
export class PartArrows extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * Add an arrow with position and direction to the part
     */
    addArrow(position: Vec3Like, direction: Vec3Like): void;
    /**
     * Sets the arrows by providing the vertices (start points) and the vectors (direction and length)
     *
     * The coordinates and vectors need to be interleaved (x0, y0, z0, x1, y1, z1, ...)
     */
    setArrows(vertexArray: ArrayLike<number>, vectorArray: ArrayLike<number>): void;
    /**
     * Sets the arrows by providing the vertices (start points) and the vectors (direction and length)
     *
     * The coordinates and vectors need to be interleaved (x0, y0, z0, x1, y1, z1, ...)
     *
     * This is the most optimal setting as the PartArrows will just hold a reference to the passed array and
     * not copy any data.
     */
    setArrowsFloat32Array(vertexArray: Float32Array, vectorArray: Float32Array): void;
    /**
     * Remove all arrows from the part
     */
    removeAllArrows(): void;
    /**
     * The single color of all arrows
     */
    get color(): Color3Like;
    set color(color: Color3Like);
    /**
     * Not implemented, always returns false
     */
    rayIntersect(_ray: Ray, _hitItem: PartHitItem): boolean;
}

/** @module cee.mrk */ /** */
/**
 * Defines a part showing an image attached to a 3d coordinate that can be shown in a {@link MarkupModel}.
 *
 * The image is provided as a {@link Texture}. The texture can be created from ImageData or from a
 * HTMLImageElement.
 *
 * The label will always be visible and rendered in front of any model. The anchor point will be rendered
 * at the depth of the specified 3d coordinate.
 *
 * **Creating the texture**
 *
 * To create the ImageData for the texture you have some options:
 *
 * 1) Create an offscreen canvas element, and use the 2d context to render text, draw lines, etc
 *
 * ```
 * let canvas = document.createElement("canvas");
 * let ctx = canvas.getContext("2d");
 *
 * canvas.width = 200;
 * canvas.height = 50;
 * ctx.font = "20px Georgia";
 * ctx.fillStyle = "red";
 * ctx.fillText("Hello EnvisionWeb!", 10, 40);
 *
 * const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
 * const texture = cee.Texture.fromImageData(imageData,
 *    { generateMipmaps: false,
 *      wrapMode: cee.TextureWrapMode.CLAMP_TO_EDGE,
 *      minFilter: cee.TextureMinFilter.LINEAR
 *    });
 * part.set(texture, pickInfo.intersectionPoint);
 * ```
 *
 * 2) Provide an RGBA array with pixel data for the image
 *
 * ```
 * const sizeX = 256;
 * const sizeY = 256;
 * const pixelArr = new Uint8ClampedArray(4*sizeX*sizeY);
 * let idx = 0;
 *
 * for (let y = 0; y < sizeY; ++y) {
 *     for (let x = 0; x < sizeX; ++x) {
 *         pixelArr[idx++]  = y%2 == 0 ? 255 : 0;
 *         pixelArr[idx++]  = x%2 == 0 ? 255 : 0;
 *         pixelArr[idx++]  = (x+y)%2 == 0 ? 255 : 0;
 *         pixelArr[idx++]  = 255;
 *     }
 * }
 *
 * const imageData  = new ImageData(pixelArr, sizeX, sizeY);
 * const texture = cee.Texture.fromImageData(imageData,
 *    { generateMipmaps: false,
 *      wrapMode: cee.TextureWrapMode.CLAMP_TO_EDGE,
 *      minFilter: cee.TextureMinFilter.LINEAR
 *    });
 * part.set(texture, pickInfo.intersectionPoint);
 * ```
 *
 * 3) Render HTML using SVG/XML
 *
 * ```
 * // Render HTML with SVG and XML
 * const canvas = document.createElement("canvas");
 * const ctx = canvas.getContext("2d");
 * canvas.width = 300;
 * canvas.height = 200;
 *
 * // Background gradient
 * {
 *    var grd = ctx.createLinearGradient(0, 0, canvas.width, 0);
 *    grd.addColorStop(0, "#eeeeee");
 *    grd.addColorStop(1, "#ffffff");
 *
 *    ctx.fillStyle = grd;
 *    ctx.fillRect(0, 0, canvas.width, canvas.height);
 * }
 *
 * // Draw border
 * {
 *    ctx.lineWidth = 2;
 *    ctx.fillStyle = "black";
 *    ctx.strokeRect(0, 0, canvas.width, canvas.height);
 * }
 *
 * const data = `
 * data:image/svg+xml,
 * <svg xmlns='http://www.w3.org/2000/svg' width='${canvas.width}' height='${canvas.height}'>
 *  <foreignObject width='100%' height='100%'>
 *    <div xmlns='http://www.w3.org/1999/xhtml' style='font-size:12px;font-family:verdana;   padding-top: 0px; padding-right: 10px;padding-bottom: 10px;padding-left: 10px;'>
 *      <h1>Region ${this.m_labelMrkModel.partCount}</h1>
 *      <table>
 *        <tr><td><b>Surface Area</b></td><td></td><td>0.02e-4 m^2</td></tr>
 *        <tr><td><b>Minimum</b></td><td><b>Average</b></td><td><b>Maximum</b></td></tr>
 *        <tr><td>0.1e-2 m^2</td><td>0.2e-2 m^2</td><td>0.4e-2 m^2</td></tr>
 *        <tr><td><b>Flow rate:</b></td><td></td><td>0.2e-2 m^3/s</td></tr>
 *        <tr><td> </td><td></td><td></td></tr>
 *        <tr><td><b>Pressure force:</b></td><td></td><td></td></tr>
 *        <tr><td>x: 0.1e-2 N</td><td>y: 0.2e-2 N</td><td>z: 0.4e-2 N</td></tr>
 *      </table>
 *    </div>
 *  </foreignObject>
 * </svg>
 * `;
 *
 * const img = new Image();
 * img.src = data;
 * const myThis = this;
 * img.onload = (_ev: Event) => {
 *    ctx.drawImage(img, 0, 0);
 *    const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
 *    const texture = cee.Texture.fromImageData(imageData,
 *      { generateMipmaps: false,
 *        wrapMode: cee.TextureWrapMode.CLAMP_TO_EDGE,
 *        minFilter: cee.TextureMinFilter.LINEAR
 *      });
 *    myThis.m_pickingImageLabelPart.set(texture, pickInfo.intersectionPoint);
 * }
 * ```
 *
 *
 * **Note:** If you want to use a NPOT (non-power-of-two) texture, make sure you provide texture
 * options {@link cee.TextureOptions} without mipmap when you generate the texture, e.g.:
 *
 * ```
 * {
 *   generateMipmaps: false,
 *   wrapMode: cee.TextureWrapMode.CLAMP_TO_EDGE,
 *   minFilter: cee.TextureMinFilter.LINEAR
 * }
 * ```
 *
 * Use {@link MarkupModel.addImageLabelPart} to create a new instance of this class.
 *
 * **Example showing HTML text rendered to SVG/XML and shown as PartImageLabel parts:**
 * ![](/images/MrkPartImageLabel.png)
 */
export class PartImageLabel extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * Set the image to use for the label and the position (3d coordinate) of the label
     */
    set(image: Texture, pos: Vec3): void;
    /**
     * Returns an active reference to the attachment appearance settings for this part.
     */
    get attachmentAppearance(): LabelAttachmentAppearance;
    /**
     * Picking
     */
    rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
}

/** @module cee.mrk */ /** */
/**
 * Defines indexed triangles that can be shown in a {@link MarkupModel}.
 *
 * Use {@link MarkupModel.addIndexedTrianglesPart} to create a new instance of this class.
 */
export class PartIndexedTriangles extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * Sets the triangles in the part using the given vertices and indices. See {@link cee.geo!MeshIndexedTriangles geo.MeshIndexedTriangles}
     * for an explanation of these arrays.
     */
    setMeshData(vertices: ArrayLike<number>, indices: ArrayLike<number>): void;
    /**
     * The color of the part.
     */
    get color(): Color3Like;
    /**  */
    set color(color: Color3Like);
    /**
     * The eye lift mode to use for this part
     */
    get eyeLift(): EyeLift;
    set eyeLift(mode: EyeLift);
    /**
     * Picking
     */
    rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
}

/** @module cee.mrk */ /** */
export class OccluderOptions {
    eyeLift?: EyeLift;
    usePolygonOffsetTowardsEye?: boolean;
}
export enum LabelDrawMode {
    WITH_DEPTH_TEST = 0,
    ALWAYS_IN_FRONT = 1
}
export enum LabelAttachmentPoint {
    NEAREST_SIDE = 0,
    CENTER = 1
}
/**
 * A callback function that can be used to draw custom content onto a label.
 *
 * Use this callback to override how labels are drawn. This gives you total freedom to draw any
 * type of label. In the callback you need to resize the canvas to a size that suits your needs,
 * and draw any text or other content onto the canvas. The label text is passed as input, but this
 * text can be a custom markup language to control the layout of the label.
 *
 * If you return if you did the drawing, return false to let the label be drawn as usual.
 *
 * **Example:**
 *
 * ```javascript
 * function myCustomDrawOntoCanvasFunction(canvas: HTMLCanvasElement, ctx: CanvasRenderingContext2D, text:string): boolean {
 *    canvas.width = 500;
 *    canvas.height = 150;
 *    const gradient = ctx.createLinearGradient(0, 0, canvas.width, canvas.height);
 *    gradient.addColorStop(0, "red");
 *    gradient.addColorStop(0.17, "orange");
 *    gradient.addColorStop(0.33, "yellow");
 *    gradient.addColorStop(0.5, "green");
 *    gradient.addColorStop(0.666, "blue");
 *    gradient.addColorStop(1, "violet");
 *
 *    // Set the fill style and draw a rectangle
 *    ctx.fillStyle = gradient;
 *    ctx.fillRect(0, 0, canvas.width, canvas.height);
 *
 *    ctx.font = "20px Comic Sans MS";
 *    ctx.fillStyle = "red";
 *    ctx.fillText(text, 50, 75);
 *
 *    return true;
 * }
 *
 * myLabelPart.setCustomDrawOntoCanvasCallback(myCustomDrawOntoCanvasFunction);
 * ```
 */
export interface CustomDrawOntoCanvasCallback {
    (canvas: HTMLCanvasElement, ctx: CanvasRenderingContext2D, text: string): boolean;
}
/**
 *
 * Defines positioned text labels that can be shown in a {@link MarkupModel}.
 *
 * Use {@link MarkupModel.addLabelsPart} to create a new instance of this class.
 *
 * **Some examples of different label styles:**
 *
 * ![](/images/MrkLabels.png)
 *
 */
export class PartLabels extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * The number of labels in the part.
     */
    get labelCount(): number;
    /**
     * Gets the text of the label at the given index.
     */
    getLabelText(index: number): string;
    /**
     * Sets the text of the label at the given index.
     */
    setLabelText(index: number, text: string): void;
    /**
     * Gets the position of the label at the given index.
     */
    getLabelPosition(index: number): Vec3;
    /**
     * Sets the position of the label at the given index.
     */
    setLabelPosition(index: number, position: Vec3): void;
    /**
     * Gets the offset position of the label at the given index.
     */
    getLabelOffsetPosition(index: number): Vec3 | null;
    /**
     * Sets the offset position of the label at the given index.
     *
     * **Example:** Move a label with the mouse
     *
     *```javascript
     * private onMouseMove(event: MouseEvent) {
     *   const label = this.m_pickingLabelPart;
     *
     *   if (label && event.ctrlKey) {
     *     const view = this.m_viewer.getViewAt(0);
     *     const labelPos = label.getLabelPosition(0);
     *
     *     // Keep label in the same distance from the camera
     *     const labelDepth = view.camera.project(labelPos).z;
     *     const oglWinPos = this.m_viewer.oglWinPosFromClientCoord(event.x, event.y);
     *     const labelOffsetPos = view.camera.unproject(
     *               {x: oglWinPos.x, y: oglWinPos.y, z: labelDepth});
     *
     *     label.setLabelOffsetPosition(0, labelOffsetPos);
     *   }
     * }
     * ```
     */
    setLabelOffsetPosition(index: number, offsetPosition: Vec3): void;
    /**
     * Gets the offset direction of the label at the given index.
     */
    getLabelOffsetDirection(index: number): Vec3 | null;
    /**
     * Sets the offset direction of the label at the given index.
     */
    setLabelOffsetDirection(index: number, offsetDirection: Vec3, flipTowardsEye: boolean): void;
    /**
     * Sets the occluder tri-mesh to use for testing the visibility of the label at the specified index.
     *
     * The specified occluder mesh is used to test if the label should be visible or not. If the mesh is
     * visible, the label will be visible. If the mesh is occluded, the label will be hidden.
     */
    setOccluderTriMesh(labelIndex: number, vertices: ArrayLike<number>, indices: ArrayLike<number> | null, options?: OccluderOptions): void;
    /**
     * Adds the given text to the part, placing it at the given position. Returns the index of the
     * new label.
     */
    add(text: string, pos: Vec3): number;
    /**
     * Adds text label with offset position. Returns the index of the new label.
     */
    addWithOffsetPosition(text: string, pos: Vec3, offsetPosition: Vec3): number;
    /**
     * Adds text label with offset direction. Returns the index of the new label.
     */
    addWithOffsetDirection(text: string, pos: Vec3, offsetDirection: Vec3): number;
    /**
     * Adds text with offset direction where the offset direction will be flipped so that it always
     * points towards the viewpoint. Returns the index of the new label.
     */
    addWithOffsetDirectionFlipTowardEye(text: string, pos: Vec3, offsetDirection: Vec3): number;
    /**
     * Deletes the text label at the given index.
     */
    deleteLabelAt(index: number): void;
    /**
     * Deletes all text labels from the part.
     */
    deleteAll(): void;
    /**
     * Returns an active reference to the appearance settings for the labels in this part.
     */
    get labelAppearance(): LabelAppearance;
    /**
     * Returns an active reference to the attachment appearance settings for this part.
     */
    get attachmentAppearance(): LabelAttachmentAppearance;
    /**
     * Point where the attachment line meets the label
     */
    get labelAttachmentPoint(): LabelAttachmentPoint;
    set labelAttachmentPoint(attachmentPoint: LabelAttachmentPoint);
    /**
     * Draw mode for the labels in this part
     */
    get drawMode(): LabelDrawMode;
    set drawMode(mode: LabelDrawMode);
    /**
     * Picking
     */
    rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
    /**
     * Specify a custom label drawing callback.
     *
     * The callback will be called for each label in the part, and can be used to draw the label in a custom way.
     *
     * Note that this callback does not consider the label appearance settings. The callback will only receive
     * the text to draw. If you return false from the callback, the label will be drawn as default.
     */
    setCustomDrawOntoCanvasCallback(callback: CustomDrawOntoCanvasCallback): void;
}

/** @module cee.mrk */ /** */
/**
 * Draw mode for line terminators
 */
export enum LineTerminatorDrawMode {
    /**
     * Draw terminators at first and last vertices only. Suitable for connected paths.
     *
     * This is the default.
     */
    SINGLE = 0,
    /**
     * Draw terminators on every line. Suitable for distinct lines.
     */
    EVERY_LINE = 1
}
/**
 * A part that can show lines in a {@link MarkupModel}.
 *
 * Use {@link MarkupModel.addLinesPart} to create a new instance of this class.
 */
export class PartLines extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * Sets the vertices for the lines.
     *
     * The coordinates need to be interleaved (x0, y0, z0, x1, y1, z1, ...)
     *
     * Lines will be drawn between [x0, y0, z0] and [x1, y1, z1], and between [x2, y2, z2] and [x3, y3, z3], ...,
     * so the number of lines will be vertices.length / 6.
     *
     * In order to draw a continuous path connecting all the given points, use {@link cee.utils!PathGenerator utils.PathGenerator}:
     *
     * ```javascript
     * const mrkModel = new cee.mrk.MarkupModel();
     * const partLines = mrkModel.addLinesPart();
     * const points: cee.Vec3[] = [ ... ];
     * const vertices = cee.utils.PathGenerator.generateVerticesForPath(points);
     * partLines.setVertices(vertices);
     * ```
     */
    setVertices(vertices: ArrayLike<number>): void;
    /**
     * Sets the vertices for the lines from a Float32Array.
     *
     * The coordinates need to be interleaved (x0, y0, z0, x1, y1, z1, ...)
     *
     * This is the most optimal setting as the PartLines will just hold a reference to the passed array and
     * not copy any data.
     *
     * Lines will be drawn between [x0, y0, z0] and [x1, y1, z1], and between [x2, y2, z2] and [x3, y3, z3], ...,
     * so the number of lines will be vertices.length / 6.
     */
    setVerticesFloat32Array(vertices: Float32Array): void;
    /**
     * Controls the line width (pixels)
     */
    get lineWidth(): number;
    set lineWidth(width: number);
    /**
     * The single color of the part
     */
    get color(): Color3Like;
    set color(color: Color3Like);
    /**
     * The line terminator draw mode
     */
    get terminatorDrawMode(): LineTerminatorDrawMode;
    set terminatorDrawMode(drawMode: LineTerminatorDrawMode);
    /**
     * Draw arrows at start of lines
     */
    setArrowStartTerminator(arrowHeadLengthInPixels: number, arrowHeadWidthInPixels: number): void;
    /**
     * Draw bars at start of lines
     */
    setBarStartTerminator(lengthInPixels: number): void;
    /**
     * Draw arrows at end of lines
     */
    setArrowEndTerminator(arrowHeadLengthInPixels: number, arrowHeadWidthInPixels: number): void;
    /**
     * Draw bars at end of lines
     */
    setBarEndTerminator(lengthInPixels: number): void;
    /**
     * Clear start and end terminators
     */
    clearTerminators(): void;
    /**
     * Picking
     */
    rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
}

/** @module cee.mrk */ /** */
/**
 * A part that can show points in a {@link MarkupModel}.
 *
 * Use {@link MarkupModel.addPointsPart} to create a new instance of this class.
 */
export class PartPoints extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * Sets the vertices for the points
     */
    setVertices(vertices: ArrayLike<number>): void;
    /**
     * Sets the vertices for the points from a Float32Array
     *
     * The coordinates needs to be interleaved (x0, y0, z0, x1, y1, z1, ...)
     *
     * This is the most optimal setting as the PartPoints will just hold a reference to the passed array and
     * not copy any data.
     */
    setVerticesFloat32Array(vertices: Float32Array): void;
    /**
     * Specify one color per point/vertex.
     *
     * The size of the array must match the number of vertices (points) in the part.
     *
     * The colors needs to be interleaved (r0, g0, b0, r1, g1, b1, ...)
     */
    setColorArray(colorArr: ArrayLike<number>): void;
    /**
     * Specify one color per point/vertex.
     *
     * Colors needs to be specified in a Uint8Array with (r0,g0,b0,r1,g1,b1,...) ordering and each component being 0..255
     *
     * This is the most optimal setting as the PartPoints will just hold a reference to the passed array and
     * not copy any data.
     */
    setColorArrayUint8Array(colorArr: Uint8Array): void;
    /**
     * The Uint8Array with the per point colors (if any).
     *
     * Colors are interleaved in a Uint8Array with (r0,g0,b0,r1,g1,b1,...) ordering and each component being 0..255
     */
    get colorArray(): Uint8Array | null;
    /**
     * Controls the point size
     */
    get pointSize(): number;
    set pointSize(pointSize: number);
    /**
     * The single color of the part if no per-point color is specified with the colorArray() property
     */
    get color(): Color3Like;
    set color(color: Color3Like);
    /**
     * Picking
     */
    rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
}

/** @module cee.mrk */ /** */
/**
 * Defines textured indexed triangles that can be shown in a {@link MarkupModel}.
 *
 * Use {@link MarkupModel.addTexturedIndexedTrianglesPart} to create a new instance of this class.
 */
export class PartTexturedIndexedTriangles extends Part {
    /**
     * Constructor
     */
    private constructor();
    /**
     * Sets the triangles in the part using the given vertices and indices. See {@link cee.geo!MeshIndexedTriangles geo.MeshIndexedTriangles} for an
     * explanation of these arrays. The textureCoords array should contain per vertex 2d texture coordinates (s,t) for
     * each vertex in vertices.
     */
    setMeshData(vertices: ArrayLike<number>, textureCoords: ArrayLike<number>, indices: ArrayLike<number>): void;
    /**
     * Sets the {@link Texture} of the part.
     */
    setTexture(texture: Texture): void;
    /**
     * Picking
     */
    rayIntersect(ray: Ray, hitItem: PartHitItem): boolean;
}

} // mrk



//
// sg2
// ===================================================================================
export namespace sg2 {

/** @module sg2 */ /** */
/**
 *
 */
export class Grid {
    /**  */
    private constructor();
    /**
     * Optional name of the grid
    */
    get name(): string;
    set name(name: string);
    /**
     * Optional name of the grid
    */
    get id(): number;
    set id(id: number);
    /**
     *
     */
    get gridData(): GridData | null;
    set gridData(gridData: GridData);
    /**
     * Returns an active reference to the settings for this grid.
     */
    get settings(): GridSettings;
    /**
     * The transformation matrix to use for this grid.
     */
    get transformationMatrix(): Mat4 | null;
    set transformationMatrix(transformationMatrix: Mat4 | null);
    /**
     * Custom data for the part. This field is not used by EnvisionWeb.
     */
    get customData(): any;
    /**
     *
     */
    set customData(data: any);
    /**
     * Performs picking on the grid
     */
    rayIntersect(ray: Ray, hitItem: GridHitItem): boolean;
    /**
     *
     */
    get quadMeshCount(): number;
    /**
     * Returns an active reference to the quad mesh at the given (zero based) index.
     */
    getQuadMeshAt(meshIndex: number): QuadMesh;
    /**
     * Returns a read only array with all the associated quad meshes
     */
    getQuadMeshArray(): ReadonlyArray<QuadMesh>;
    /**
     *
     */
    addQuadMesh(quadMesh: QuadMesh): void;
}

/** @module sg2 */ /** */
/**
 *
 */
export class GridData {
    /**
     * Constructor
     */
    constructor(nodeCountI: number, nodeCountJ: number, elevationArr?: ArrayLike<number>, minElevation?: number, maxElevation?: number);
    /**
     *
     */
    get nodeCountI(): number;
    /**
     *
     */
    get nodeCountJ(): number;
    /**
     *
     */
    get nodeCount(): number;
    /**
     *
     */
    get cellCountI(): number;
    /**
     *
     */
    get cellCountJ(): number;
    /**
     *
     */
    get cellCount(): number;
    /**
     *
     */
    get visibleCellCount(): number;
    /**
     *
     */
    get spacingI(): number;
    set spacingI(spacing: number);
    /**
     *
     */
    get spacingJ(): number;
    set spacingJ(spacing: number);
    /**
     *
     */
    get offsetI(): number;
    set offsetI(offset: number);
    /**
     *
     */
    get offsetJ(): number;
    set offsetJ(offset: number);
    /**
     *
     */
    nodeIndexFromIJ(i: number, j: number): number;
    /**
     *
     */
    nodeIJFromIndex(nodeIndex: number): {
        i: number;
        j: number;
    };
    /**
     * Returns the elevation at the given i,j coordinate (world coords, not integer indices)
     */
    elevationAtPoint(iCoord: number, jCoord: number): number;
    /**
     *
     */
    get elevationArr(): ArrayLike<number>;
    /**
     *
     */
    get minElevation(): number | undefined;
    /**
     *
     */
    get maxElevation(): number | undefined;
    /**
     *
     */
    setElevationArr(elevationArr: ArrayLike<number>, minElevation?: number, maxElevation?: number): void;
    /**
     *
     */
    setNodeScalarResultArr(scalarArr: ArrayLike<number>): void;
    /**
     *
     */
    get nodeScalarResultArr(): ArrayLike<number> | null;
    /**
     *
     */
    setCellScalarResultArr(scalarArr: ArrayLike<number>): void;
    /**
     *
     */
    get cellScalarResultArr(): ArrayLike<number> | null;
    /**
     *
     */
    toNodeResultValues(cellResultValues: ArrayLike<number>): Float32Array;
    /**
     *
     */
    getScalarResultRange(): Range;
    /**
     *
     */
    computeVisibilitiesFromElevations(): void;
    /**
     *
     */
    get nodeVisibilityArr(): ReadonlyArray<boolean> | null;
    /**
     *
     */
    get cellVisibilityArr(): ReadonlyArray<boolean> | null;
    /**
     *
     */
    rayIntersect(ray: Ray, gridHitItem: GridHitItem): boolean;
    /**
     *
     */
    rayIntersectRange(ray: Ray, gridHitItem: GridHitItem, fromI: number, fromJ: number, cellCountI: number, cellCountJ: number): boolean;
    /**
     * Computes an intersection line or -line segments in this, given a starting point and an end point
     * (either outside or inside the grid). Returns array of line segments forming the line projected
     * down on the grid.
     *
     * Param:	fX1 - first point x component
     *			fY1 - first point y component
     *			fX2 - second point x component
     *			fY2 - second point y component
     *
     */
    compute2DLineSegmentIntersect(fX1: number, fY1: number, fX2: number, fY2: number): Vec3[];
    /**
     *
     */
    static fromElevations(nodeCountI: number, nodeCountJ: number, elevationArr: ArrayLike<number>, minElevation?: number, maxElevation?: number): GridData;
}

/** @module sg2 */ /** */
/**
 * GridHitItem contains the result of a picking operation (`rayIntersect()`) on a Grid.
 */
export class GridHitItem {
    /**
     * The squared distance between the intersection point and the origin of the ray that was passed to rayIntersect().
     */
    distanceSquared: number;
    /**
     * The index of the cell that was hit
     */
    cellIndex: number;
    /**
     * The intersection point.
     */
    intersectionPoint: Vec3 | null;
}

/** @module sg2 */ /** */
/**
 * GridQuery allows extraction of data from a DataGrid.
 */
export class GridQuery {
    /**  */
    constructor(gridData: GridData);
    /**
     *
     */
    setTransformationMatrix(transformationMatrix: Mat4 | null): void;
    /**
     *
     */
    computeOutline(): Float32Array;
}

export enum DrawStyle {
    /**
     * Render the grid as surface.
     */
    SURFACE = 0,
    /**
     * Render the grid as surface with an overlay of the grid lines
     */
    SURFACE_MESH = 1,
    /**
     * Render the grid as surface with an overlay of the outline mesh
     */
    SURFACE_OUTLINE_MESH = 2,
    /**
     * Render the grid as lines
     */
    LINES = 3,
    /**
     * Render the grid as outline
     */
    OUTLINE = 4
}
/**
 *
 */
export class GridSettings {
    /** */
    private constructor();
    /**
     * The visibility of the grid
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * The color of the grid. Note that the returned color cannot be modified.
     */
    get color(): Color3Like;
    set color(color: Color3Like);
    /**
     * The specification of how to render the grid
     */
    get drawStyle(): DrawStyle;
    set drawStyle(drawStyle: DrawStyle);
    /**
     *
     */
    get scalarMapper(): ScalarMapperContinuousDomain | null;
    set scalarMapper(scalarMapper: ScalarMapperContinuousDomain | null);
    /**
     *
     */
    get showPerCellResults(): boolean;
    set showPerCellResults(v: boolean);
}

/** @module sg2 */ /** */
/**
 * HitItem contains the result of a picking operation (`rayIntersect()`) on a StructGrid2dModel.
 */
export interface HitItem {
    /**
     * The index of the grid within the StructGrid2dModel
     */
    gridIndex: number;
    /**
     * The index of the cell that was hit
     */
    cellIndex: number;
    /**
     * The 3d point (in world coordinates) of the intersection between the ray and the primitive that was hit
     */
    intersectionPoint: Vec3;
}

/** @module sg2 */ /** */
/**
 *
 */
export class QuadMesh {
    /**  */
    constructor();
    /**
     *
     */
    setMeshData(vertices: ArrayLike<number>, indices: ArrayLike<number>): void;
    /**
     * The visibility of the quad mesh
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * The color of the mesh. Note that the returned color cannot be modified.
     * The color may be set to null in which case the mesh gets the same color as the parent grid.
     */
    get color(): Color3Like | null;
    set color(color: Color3Like | null);
    /**
     * A readonly array containing the vertices of the mesh
     */
    get vertexArray(): ArrayLike<number>;
    /**
     * A readonly array containing the indices of the mesh
     */
    get indexArray(): ArrayLike<number>;
    /**
     *
     */
    setNodeScalarResultArr(scalarArr: ArrayLike<number> | null): void;
    /**
     *
     */
    get nodeScalarResultArr(): ArrayLike<number> | null;
}

/** @module sg2 */ /** */
/**
 *
 */
export class StructGrid2dModel extends Model {
    /**
     * Constructor
     */
    constructor();
    /**
     * Name of the model.
     */
    get name(): string;
    set name(name: string);
    /**
     * The number of grids in the model.
     */
    get gridCount(): number;
    /**
     * Returns a read only array with all grids
     */
    getGridArray(): ReadonlyArray<Grid>;
    /**
     * Creates a new grid and adds it to the model.
     *
     * Returns the newly created grid.
     */
    addGrid(): Grid;
    /**
     * Returns reference to the grid at the given (zero based) index.
     */
    getGridAt(gridIndex: number): Grid;
    /**
     * Returns reference to the grid with the given gridId. Returns null when no match is found.
     */
    getGridById(gridId: number): Grid | null;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the model.
     */
    getBoundingBox(options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns default camera configuration, which is always null for this model.
     */
    getDefaultCameraConfig(): null;
    /**
     * Performs picking on the model.
     *
     * If something was hit, returns a HitItem containing information about the part and primitive that was hit.
     *
     * If nothing was hit, returns null.
     */
    rayIntersect(ray: Ray): HitItem | null;
}

/** @module sg2 */ /** */
export interface RemoteLoaderModelInfo {
    boundingBox: BoundingBox;
}
export class RemoteLoaderStatusInfo {
    totalGridCount: number;
    receivedGridCount: number;
}
export class RemoteLoaderTimingInfo {
    elapsedTime_ms: number;
}
export interface RemoteLoaderInitializationCompleteCallback {
    (modelInfo: RemoteLoaderModelInfo): void;
}
export interface RemoteLoaderCompleteCallback {
    (error: Error | null): void;
}
/**
 *
 *
 */
export class StructGrid2dModelRemoteLoader {
    /**
     *
     */
    constructor(serverUrl: string);
    /**
     *
     */
    setInitializationCompleteCallback(initializationCompleteCallback?: RemoteLoaderInitializationCompleteCallback): void;
    /**
     *
     */
    setDepthScaleFactor(depthScaleFactor: number): void;
    /**
     *
     */
    loadModel(modelKey: string, frameIndex: number, targetModel: StructGrid2dModel, loadingCompleteCallback?: RemoteLoaderCompleteCallback): void;
    /**
     *
     */
    cancelLoading(): void;
    /**
     *
     */
    getStatusInfo(): RemoteLoaderStatusInfo;
    /**
     *
     */
    getTimingInfo(): RemoteLoaderTimingInfo;
}

} // sg2



//
// ug
// ===================================================================================
export namespace ug {

/**
 * Callback that will be invoked whenever the animation control changes the current frame.
 *
 * Can be used to synchronize UI elements with the model.
 */
export interface AnimationFrameChangedCallback {
    (frameIndex: number): void;
}
/**
 * Handles animation of a {@link RemoteModel}.
 *
 * With this class you can control state animations (animations across the states of the CAE analysis),
 * particle trace animations and mode shape animations.
 *
 * To start a state animation, specify the states to animate over with the {@link ModelSpec.stateIdArray} property and call {@link runAnimation runAnimation(true)}.
 *
 * To start a particle trace animation, set the {@link particleTraceAnimationStepCount} property and call
 * {@link runParticleTraceAnimation runParticleTraceAnimation(true)}. Note that you must first create a particle trace by calling
 * {@link RemoteModel.addParticleTraceGroup}.
 *
 * To start a mode shape animation, set the {@link ModelSpec.modeShapeAnimationType} and
 * {@link ModelSpec.modeShapeFrameCount} properties and then call {@link runAnimation runAnimation(true)}. Note that you must first set a displacement result on the
 * model with {@link ModelSpec.displacementResultId}, and that {@link ModelSpec.stateIdArray} must contain exactly one state id.
 *
 * You can access the animation object from the remote model with the {@link RemoteModel.animation} property.
 */
export class Animation {
    /**
     *
     */
    private constructor();
    /**
     * The target animation speed in frames per second (fps).
     *
     * This will be the maximum animation speed, but the actual speed may be lower for large
     * models or slow clients.
     */
    get targetFrameRate(): number;
    /**
     *
     *
     */
    set targetFrameRate(framesPerSecond: number);
    /**
     * The number of steps to use for the particle trace animation.
     *
     * The number of steps will be used to calculate the delta time for each step in the animation
     * based on the total time of all active traces.
     */
    get particleTraceAnimationStepCount(): number;
    /**
     *
     *
     */
    set particleTraceAnimationStepCount(numSteps: number);
    /**
     * Starts a state (transient) or mode shape animation.
     *
     * The steps are configured in the {@link ModelSpec} of the {@link RemoteModel}.
     *
     * To start a state (transient) animations, set the states you would like to animate over with {@link ModelSpec.stateIdArray}.
     * The order of the states in the animation will be the same as in the array. Note that {@link ModelSpec.modeShapeFrameCount}
     * MUST be set to 0 for state (transient) animations.
     *
     * To start a mode shape animation, set the {@link ModelSpec.modeShapeAnimationType} and
     * {@link ModelSpec.modeShapeFrameCount} properties and then call {@link runAnimation runAnimation(true)}. Note that you must first
     * set a displacement result on the model with {@link ModelSpec.displacementResultId}, and that {@link ModelSpec.stateIdArray}
     * must contain exactly one state id.
     */
    runAnimation(run: boolean): void;
    /**
     * Starts a particle trace animation.
     *
     * The number of steps to use for the animation can be set with {@link particleTraceAnimationStepCount}.
     */
    runParticleTraceAnimation(run: boolean): void;
    /**
     * Returns true if either a state or mode shape animation is running
     */
    isModelAnimationRunning(): boolean;
    /**
     * Returns true if either a state, mode shape or particle trace animation is running
     */
    isAnyAnimationRunning(): boolean;
    /**
     * Sets the first step of the animation (if any) as the current step. This will stop the animation.
     */
    setFirstFrame(): void;
    /**
     * Sets the last step of the animation (if any) as the current step. This will stop the animation.
     */
    setLastFrame(): void;
    /**
     * Sets the next step of the animation (if any) as the current step, wrapping around to the first step if on
     * the last step. This will stop the animation.
     */
    setNextFrame(): void;
    /**
     * Sets the previous step of the animation (if any) as the current step, wrapping around to the last step if on
     * the first step. This will stop the animation.
     */
    setPreviousFrame(): void;
    /**
     * Sets a handler function that will be called whenever a progress indication packet is received from the
     * visualization server.
     */
    setAnimationFrameChangedCallback(animationFrameChangedCallback: AnimationFrameChangedCallback): void;
}

/** @module cee.ug */ /** */
/**
 * The result of a client side picking call on a {@link RemoteModel}.
 *
 * Returned by {@link RemoteModel.clientSideRayIntersect} and {@link TrianglePicker}.
 *
 * This class only contains data available on the client. For hit items with objectType = PART, {@link QueryElementInfo.executeQueryByClientSideHitItems} can
 * be used to fetch complete data from the server.
 */
export class ClientSideHitItem {
    /**
     * The 3d point (in world coordinates) on the surface that was hit.
     *
     * This is the actual point that was hit.
     *
     * Note that this property is only set by rayIntersect(). It is left to null by TrianglePicker.
     */
    get intersectionPoint(): Vec3 | null;
    /**
     * The type of object (part/iso/cut/isovol) that was hit
     */
    get objectType(): ObjectType | undefined;
    /**
     * The id of the object (part/iso/cut/isovol) that was hit
     */
    get objectId(): number | undefined;
    /**
     * The index of the CAE geometry.
     *
     * In almost all cases this will be 0. If using a partially adaptive model with remeshing only on parts of the model (e.g. in a Forging process)
     * the concept of multiple geometries might be relevant.
     */
    get geometryIndex(): number | undefined;
    /**
     * The triangle vertices of the geometry that was hit
     */
    get vertices(): number[];
}

/**
 * Specification of a cutting plane (both parameters and attributes) in a {@link RemoteModel}.
 *
 * Use this object to control the position, settings and visual attributes of a cutting plane. The
 * position of the cutting plane is defined with {@link point} and {@link normal}. You can map a
 * scalar result onto the cutting plane with {@link mapScalarResultId}, and show vectors sampled in a regular
 * grid with {@link mapVectorResultId}. The spacing of this regular grid is defined with {@link vectorGridSpacing}.
 *
 * You can specify whether to clip the model in the cutting plane's plane with {@link clipping}, show the
 * intersected element mesh with {@link showElementMesh} and set its {@link opacity}.
 *
 * Please note that cutting planes are more that just geometric clipping planes. They intersect the volume
 * elements and produce a surface onto which results can be mapped.
 *
 * To create a cutting plane, use {@link RemoteModel.addCuttingPlane}.
 *
 * **Example:** Create two cutting planes:
 *
 *```javascript
 * var modelDir = myModel.modelDirectory;
 *
 * // Find basis for position and map scalar result
 * var bb = myModel.getBoundingBox();
 * var halfExtent = bb.getExtent().x/2;
 * var mapScalarId = -1;
 *
 * if (modelDir.scalarResultArray.length > 0) {
 *     mapScalarId = modelDir.scalarResultArray[0].id;
 * }
 *
 * // Create plane 1
 * var plane1 = myModel.addCuttingPlane();
 * plane1.point = cee.Vec3.add(bb.getCenter(), new cee.Vec3(0.5*halfExtent, 0, 0));
 * plane1.normal = new cee.Vec3(1,0,0);
 * plane1.mapScalarResultId = mapScalarId;
 *
 * // Create plane 2
 * var plane2 = myModel.addCuttingPlane();
 * plane2.point = bb.getCenter();
 * plane2.point = cee.Vec3.sub(bb.getCenter(), new cee.Vec3(0.5*halfExtent, 0, 0));
 * plane2.normal = new cee.Vec3(1,0,0);
 * plane2.mapScalarResultId = mapScalarId;
 * plane2.showElementMesh = true;
 *
 * // Set model to outline to show the cutting planes
 * myModel.setDrawStyleAllParts(cee.ug.DrawStyle.OUTLINE);
 *```
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/CuttingPlane.png)
 */
export class CuttingPlane {
    /**
     *
    */
    private constructor();
    /**
     * The id of the cutting plane. This is assigned by the system when you call {@link RemoteModel.addCuttingPlane}
     * and is used to identify the cutting plane.
     */
    get id(): number;
    /**
     * Visibility of the cutting plane. Use this to show or hide a cutting plane in the 3D Viewer.
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * A point in the plane. Together with the normal property this defines the plane that the cutting plane is in.
     */
    get point(): Vec3Like;
    /**  */
    set point(point: Vec3Like);
    /**
     * The normal of the cutting plane. Defines its orientation.
     */
    get normal(): Vec3Like;
    set normal(normal: Vec3Like);
    /**
     * The eye lift mode to use for this cutting plane.
     *
     * Eye lift can be used when facing z fighting issues (triangles rendered in the same plane).
     * By applying eye lift to one part, it will be moved slightly towards the eye, resolving the
     * z fighting issues. The current version offers 3 eye lift factors to choose from.
     */
    get eyeLift(): EyeLift;
    set eyeLift(mode: EyeLift);
    /**
     * Toggle lighting of the cutting plane on/off.
     */
    get lighting(): boolean;
    set lighting(lighting: boolean);
    /**
     * The id of the scalar result to show on the cutting plane.
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     * You can change the settings for the scalar in the {@link ScalarSettings} object.
     *
     * Set to -1 to show no scalars on the cutting plane.
     */
    get mapScalarResultId(): number;
    /**
     *
     *
    */
    set mapScalarResultId(resultId: number);
    /**
     * The id of the vector result to show on the cutting plane.
     * This id must refer to one of the vector results in {@link ModelDirectory.vectorResultArray}.
     * The vectors are shown in a regular grid. The spacing of this grid can be set with {@link vectorGridSpacing}.
     * The settings for the vector arrows can be changed with the {@link VectorSettings} object.
     *
     * Set to -1 to show no vectors on the cutting plane.
     */
    get mapVectorResultId(): number;
    set mapVectorResultId(resultId: number);
    /**
     * The id of the contour lines result to show on the cutting plane.
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarLinesResultArray}.
     *
     * Set to -1 to show no contour lines on the cutting plane.
     */
    get mapContourLinesResultId(): number;
    set mapContourLinesResultId(resultId: number);
    /**
     * The spacing of the vectors shown on the cutting plane. The vector arrows are resampled into a regular grid
     * before being rendered on the cutting plane. This property defines the spacing between each vector arrow
     * on the cutting plane. The value is relative to the current extent of the model.
     *
     * The default is 0.02
     */
    get vectorGridSpacing(): number;
    /**  */
    set vectorGridSpacing(spacing: number);
    /**
     * If true, the regular grid vectors are projected onto the cutting plane, making all the vectors
     * parallel to the cutting plane surface.
     *
     * The default is false.
     */
    get projectVectorsOnPlane(): boolean;
    set projectVectorsOnPlane(project: boolean);
    /**
     * Specify if the cutting plane should show a crinkle cut surface.
     *
     * If enabled, the cutting plane surface will be the combined surface of all elements intersected
     * by the cutting plane. So the cutting plane will show the tesselation of all intersected elements.
     *
     * This is useful for inspecting and visualizing the mesh of a volume element model.
     *
     * The default is false.
     */
    get crinkleCutSurface(): boolean;
    set crinkleCutSurface(show: boolean);
    /**
     * Whether the surface of the cutting plane should be visible.
     *
     * The default is true.
     */
    get showSurface(): boolean;
    set showSurface(show: boolean);
    /**
     * Whether the cutting plane should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
    /**
     * Whether the model should be clipped. If true, the model will be clipped at the
     * cutting plane position
     */
    get clipping(): boolean;
    set clipping(clipping: boolean);
    /**
     * Whether the intersected element mesh should be rendered. If true, the mesh resulting from the intersection
     * of the cutting plane with the element model will be overlaid on the cutting plane.
     */
    get showElementMesh(): boolean;
    set showElementMesh(show: boolean);
    /**
     * Opacity of the cutting plane. 0.0 means fully transparent (invisible), 1.0 means fully opaque.
     */
    get opacity(): number;
    set opacity(opacity: number);
    /**
     * The color of the cutting plane surface if not showing a result and useSourcePartColor is false
     */
    get surfaceColor(): Color3Like;
    /**  */
    set surfaceColor(clr: Color3Like);
    /**
     * If set to true, the cutting plane will be colored by the source part, so this plane will end
     * up with different colors based on the color of the parts the cutting plane intersects
     */
    get useSourcePartColor(): boolean;
    set useSourcePartColor(use: boolean);
    /**
     * If set to true, the cutting plane will be computed from only the visible parts. Any part that
     * is not visible will not contribute to the cutting plane.
     */
    get computeFromVisibleParts(): boolean;
    set computeFromVisibleParts(visiblePartsOnly: boolean);
    /**
     * The id of the scalar result used filter on the cutting plane.
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     *
     * Set to -1 to turn off scalar filtering on the cutting plane.
     */
    get filterScalarResultId(): number;
    /**
     * The minimum range of the scalar result used for filtering visibility of the cutting plane
     *
     * To set a filtering range, use the {@link setScalarFilteringVisibleRange} function.
     */
    get filterScalarRangeMinimum(): number | undefined;
    /**
     * The maximum range of the scalar result used for filtering visibility of the cutting plane
     *
     * To set a filtering range, use the {@link setScalarFilteringVisibleRange} function.
     */
    get filterScalarRangeMaximum(): number | undefined;
    /**
     * Is true if the cutting plane is precomputed and cannot be changed
     */
    get isPrecomputed(): boolean;
    /**
     * Sets the scalar filtering visibility range for cutting plane
     *
     * Specify a filter for a cutting plane by defining a specific result id (resultId) and a scalar
     * range from minimum to maximum.
     * The filter allows you to control the visibility of areas on the cutting plane based on scalar values,
     * making areas outside the specified range invisible.
     *
     * A common use case for this functionality is to restrict the visibility of a cutting plane to a
     * specific isovolume. By configuring the cutting plane filter with the same result id and scalar range
     * as the isovolume, you can ensure that the cutting plane surface is only visible within the isovolume.
     *
     * For a visual representation and example scenarios regarding isovolumes and cutting planes with and
     * without scalar filtering, please refer to the images below.
     *
     * ![](/images/cuttingplane_nofilter.png)
     * ![](/images/cuttingplane_filter.png)
     *
     * @param resultId The id for the result to which this filter should be applied.
     * @param min The minimum scalar value for filtering. Areas with scalar values below this threshold will be set invisible.
     * @param max The maximum scalar value for filtering. Areas with scalar values above this threshold will be set invisible.
     */
    setScalarFilteringVisibleRange(resultId: number, min: number, max: number): void;
    /**
     * Gets the settings for this cutting plane as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): CuttingPlaneProperties;
    /**
     * Applies the settings in the given properties object to this cutting plane
     */
    setFromProperties(props: Partial<CuttingPlaneProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link CuttingPlane}
 */
export interface CuttingPlaneProperties {
    /**
     * See {@link CuttingPlane.id}
     */
    id: number;
    /**
     * See {@link CuttingPlane.visible}
     */
    visible: boolean;
    /**
     * See {@link CuttingPlane.point}
     */
    point: Vec3Like;
    /**
     * See {@link CuttingPlane.normal}
     */
    normal: Vec3Like;
    /**
     * See {@link CuttingPlane.eyeLift}
     */
    eyeLift: EyeLift;
    /**
     * See {@link CuttingPlane.lighting}
     */
    lighting: boolean;
    /**
     * See {@link CuttingPlane.mapScalarResultId}
     */
    mapScalarResultId: number;
    /**
     * See {@link CuttingPlane.mapVectorResultId}
     */
    mapVectorResultId: number;
    /**
     * See {@link CuttingPlane.mapContourLinesResultId}
     */
    mapContourLinesResultId: number;
    /**
     * See {@link CuttingPlane.vectorGridSpacing}
     */
    vectorGridSpacing: number;
    /**
     * See {@link CuttingPlane.projectVectorsOnPlane}
     */
    projectVectorsOnPlane: boolean;
    /**
     * See {@link CuttingPlane.crinkleCutSurface}
     */
    crinkleCutSurface: boolean;
    /**
     * See {@link CuttingPlane.showSurface}
     */
    showSurface: boolean;
    /**
     * See {@link CuttingPlane.highlight}
     */
    highlight: boolean;
    /**
     * See {@link CuttingPlane.clipping}
     */
    clipping: boolean;
    /**
     * See {@link CuttingPlane.showElementMesh}
     */
    showElementMesh: boolean;
    /**
     * See {@link CuttingPlane.opacity}
     */
    opacity: number;
    /**
     * See {@link CuttingPlane.surfaceColor}
     */
    surfaceColor: Color3Like;
    /**
     * See {@link CuttingPlane.useSourcePartColor}
     */
    useSourcePartColor: boolean;
    /**
     * See {@link CuttingPlane.computeFromVisibleParts}
     */
    computeFromVisibleParts: boolean;
    /**
     * See {@link CuttingPlane.isPrecomputed}
     */
    filterScalarResultId: number;
    /**
     * See {@link CuttingPlane.filterScalarResultId}
     */
    filterScalarRangeMinimum: number | undefined;
    /**
     * See {@link CuttingPlane.filterScalarRangeMinimum}
     */
    filterScalarRangeMaximum: number | undefined;
    /**
     * See {@link CuttingPlane.filterScalarRangeMaximum}
     */
    isPrecomputed: boolean;
}

/** @module cee.ug */ /** */
/**
 * Helper functions for cutting planes
 */
export class CuttingPlaneUtils {
    /**
     * Gets a position from a relative position along the given normal on the given bounding box.
     *
     * This is useful for implementing a slider moving the cutting plane back and forth in the direction of
     * the plane's normal vector.
     *
     * @param relVal The relative value to get the position for (0..1)
     * @param normal The normal direction to compute the position in
     * @param boundingBox The bounding box defining the range of positions for the point (usually the model bounding box)
     */
    static getPositionFromRelativeNormalPosition(relVal: number, normal: Vec3Like, boundingBox: BoundingBox): Vec3;
    /**
     * Gets a relative position along the given normal and bounding box for the given point
     *
     * Useful for updating the slider position based on the current position of a cutting plane.
     *
     * @param point The point to compute the relative position for
     * @param normal The normal direction to use for the computation
     * @param boundingBox The bounding box defining the range of positions for the point (usually the model bounding box)
     */
    static getRelativeNormalPosition(point: Vec3Like, normal: Vec3Like, boundingBox: BoundingBox): number;
}

/** @module cee.ug */ /** */
/**
 * Scaling mode to use for displacements.
 */
export enum DisplacementScaleMode {
    /**
     * Absolute scaling of displacements. Displacements will be scaled by the specified factor and rendered in world coordinates.
     */
    ABSOLUTE_SCALING = 0,
    /**
     * Relative scaling of displacements. Displacements will be scaled relative to the current model's bounding box (BB).
     * A relative scale of 1 means the largest displacement will have its length equal to the length of the model bounding box's diagonal.
     * Typical usable values for the scale factor are in the range 0 to 0.5.
     */
    RELATIVE_SCALING = 1
}
/**
 * Specification of how to render parts with the given displacement result.
 *
 * With this object you can control the (absolute) scaling of displacements.
 */
export class DisplacementSettings {
    /**
     *
    */
    private constructor();
    /**
     * The id (>=0) of the displacement result.
     * This id must refer to one of the displacement results in {@link ModelDirectory.displacementResultArray}.
     */
    get resultId(): number;
    /**
     * The scale factor to use for the displacement result.
     *
     * The behavior depends on the chosen {@link scaleMode}. For absolute displacements, they will be simply multiplied by this factor.
     *
     * For relative displacements, this will scale them in a way that the largest displacement will have its length equal to
     * the length of the model bounding box's diagonal multiplied by this factor. Typical usable values for relative displacements are in the range 0 to 0.5.
     */
    get scaleFactor(): number;
    /**   */
    set scaleFactor(scaleFactor: number);
    /**
     * The scaling mode to use for displacement results (absolute or relative). The default is absolute.
     */
    get scaleMode(): DisplacementScaleMode;
    /** <nbsp>  */
    set scaleMode(scaleMode: DisplacementScaleMode);
    /**
     * Gets the settings for this displacement settings as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): DisplacementSettingsProperties;
    /**
     * Applies the settings in the given properties object to this displacement settings.
     */
    setFromProperties(props: Partial<DisplacementSettingsProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link DisplacementSettings}
 */
export interface DisplacementSettingsProperties {
    /**
     * See {@link DisplacementSettings.resultId}
     */
    resultId: number;
    /**
     * See {@link DisplacementSettings.scaleFactor}
     */
    scaleFactor: number;
    /**
     * See {@link DisplacementSettings.scaleMode}
     */
    scaleMode: DisplacementScaleMode;
}

/** @module cee.ug */ /** */
/**
 * Helper class for highlighting objects in a {@link RemoteModel} based on picking information.
 */
export class HighlightHelper {
    /**
     * Creates a new highlight helper for the given model.
     */
    constructor(model: ug.RemoteModel);
    /**
     * Toggles whether multiple objects can be highlighted simultaneously.
     */
    setMultiHighlight(multiHighlight: boolean): void;
    /**
     * Removes highlighting from all objects.
     */
    clearAll(): void;
    /**
     * Highlights the given object.
     */
    add(objectType: ug.ObjectType, objectId: number, geometryIndex: number): void;
    /**
     * Toggles whether the given object is highlighted.
     */
    toggle(objectType: ug.ObjectType, objectId: number, geometryIndex: number): void;
    /**
     * Removes highlighting from the given object.
     */
    remove(objectType: ug.ObjectType, objectId: number, geometryIndex: number): void;
}

/** @module cee.ug */ /** */
/**
 * Interface for an object describing the result of a picking action on a {@link RemoteModel}.
 *
 * This object is provided to the {@link RayIntersectCallback}.
 */
export interface HitItem {
    /**
     * The index of the frame in which the picking occurred. This is 0 unless there is an animation.
     */
    frameIndex: number;
    /**
     * Whether anything was hit during the action. If false, the other properties in this object will be undefined.
     */
    anythingHit: boolean;
    /**
     * The type of object (part/iso/cut/isovol) that was hit
     */
    objectType: ObjectType;
    /**
     * The id of the object (part/iso/cut/isovol) that was hit
     */
    objectId: number;
    /**
     * The index of the object (part/iso/cut/isovol) that was hit
     */
    objectIndex: number;
    /**
     * The name of the object (part/iso/cut/isovol) that was hit
     */
    objectName: string;
    /**
     * The index of the CAE geometry.
     *
     * In almost all cases this will be 0. If using a partially adaptive model with remeshing only on parts of the model (e.g. in a Forging process)
     * the concept of multiple geometries might be relevant.
     */
    geometryIndex: number;
    /**
     * The id of the element in the data model on the server that was hit
     */
    elementId: number;
    /**
     * The index (zero based) of the element in the data model on the server that was hit
     */
    elementIndex: number;
    /**
     * The type of the element in the data model on the server that was hit, for example 'Quad', 'Tetrahedron', 'Hexahedron'
     */
    elementType: string;
    /**
     * The volume of the element (if applicable)
     */
    elementVolume: number;
    /**
     * The area of the element (if applicable)
     */
    elementArea: number;
    /**
     * The local index (zero based) of the element face that was hit
     */
    elementFaceIndex: number;
    /**
     * The local index (zero based) of the closest element edge to the actual intersection point in the data model on the server that was hit
     */
    elementEdgeIndex: number;
    /**
     * The local index (zero based) of the closest element node to the actual intersection point in the data model on the server that was hit
     */
    elementNodeIndex: number;
    /**
    * The id of the closest node to the actual intersection point in the data model on the server that was hit
    */
    nodeId: number;
    /**
     * The index (zero based) of the closest node to the actual intersection point in the data model on the server that was hit
     */
    nodeIndex: number;
    /**
     * The 3d point (in world coordinates) of the closest node as identified by nodeId/nodeIndex
     *
     * Use intersectionPoint for the actual point on the model that was hit
     */
    nodePosition: Vec3;
    /**
    * The 3d point (in world coordinates) on the surface that was hit.
    *
    * This is the actual point that was hit
    */
    intersectionPoint: Vec3;
    /**
     * The normal of the surface at the point where the surface was hit.
     */
    intersectionPointNormal: Vec3;
    /**
     * The scalar result in the element that was hit.
     */
    elementResult: number;
    /**
     * Whether the element result is interpolated (e.g. from a nodal result). False if the result is an actual per element result.
     */
    elementResultIsInterpolated: boolean;
    /**
     * The scalar result in the closest node as indicated by {@link nodeId}/{@link nodeIndex}.
     */
    nodeResult: number;
    /**
     * Whether the node result is interpolated (e.g. from a per element result). False if the result is an actual per node result.
     */
    nodeResultIsInterpolated: boolean;
    /**
     * The scalar result in the closest element node. Only defined if the current result is per element node
     */
    elementNodeResult: number;
    /**
     * The interpolated scalar result in the {@link intersectionPoint}.
     */
    intersectionPointResult: number;
    /**
     * The name of the scalar that the results {@link elementResult} and {@link nodeResult} apply to.
     */
    scalarResultName: string;
    /**
     * A tessellation of triangles of the element that was hit.
     *
     * This array contains x,y,z values for each triangle vertex. So there will be 9 values (3 vertices * (x,y,z)) per triangle.
     * This can be used to highlight the selected element using the geometry or the markup model.
     *
     */
    elementTriangleVertices: number[];
}

/**
 * Specification of an isosurface (both parameters and attributes) in a {@link RemoteModel}.
 *
 * Use this object to control the settings and attributes of an isosurface. The isosurface is defined
 * by specifying the scalar to compute from (with {@link isoScalarResultId}) and the value to compute the surface
 * for (with {@link isoValue}). The result is a surface within the model containing all points where the scalar
 * result has the given value.
 *
 * You can map any scalar result onto the isosurface with {@link mapScalarResultId} and also map
 * a vector result with {@link mapVectorResultId}. The settings for the mapped results can
 * be controlled with the {@link ScalarSettings} and {@link VectorSettings} objects.
 *
 * To create an isosurface, use {@link RemoteModel.addIsosurface}.
 *
 * **Example:** Show an isosurface
 *
 *```javascript
 * var modelDir = myModel.modelDirectory;
 *
 * // Add iso surface if we have a scalar result
 * if (modelDir.scalarResultArray.length > 0) {
 *     var iso = myModel.addIsosurface();
 *     iso.isoScalarResultId = modelDir.scalarResultArray[0].id;
 *
 *     if (myModel.getScalarResultMinimumValue(iso.isoScalarResultId) != undefined) {
 *         iso.isoValue = (myModel.getScalarResultMinimumValue(iso.isoScalarResultId)
 *               + myModel.getScalarResultMaximumValue(iso.isoScalarResultId))/2;
 *     } else {
 *         iso.isoValue = 0.5;
 *     }
 *
 *     if (modelDir.scalarResultArray.length > 1) {
 *         iso.mapScalarResultId = modelDir.scalarResultArray[1].id;
 *     } else {
 *         iso.mapScalarResultId = modelDir.scalarResultArray[0].id;
 *     }
 * }
 *
 * // Set model to outline to show the cutting planes
 * myModel.setDrawStyleAllParts(cee.ug.DrawStyle.OUTLINE);
 *```
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/Isosurface.png)
 */
export class Isosurface {
    /**
     *
     */
    private constructor();
    /**
     * The id of the isosurface. This is assigned by the system when you call {@link RemoteModel.addIsosurface}
     * and is used to identify the isosurface.
     */
    get id(): number;
    /**
     * Visibility of the isosurface. Use this to show or hide an isosurface in the 3D Viewer.
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * The value to compute the isosurface from. The value of the scalar result with id {@link isoScalarResultId}
     * will be equal to this value at all points on the isosurface.
     */
    get isoValue(): number;
    /**   */
    set isoValue(isoValue: number);
    /**
     * The scalar result to compute the isosurface from. This property is mandatory and must refer to one
     * of the scalar results in {@link ModelDirectory.scalarResultArray}.
     */
    get isoScalarResultId(): number;
    /**
    */
    set isoScalarResultId(isoScalarResultId: number);
    /**
     * The id of the scalar result to show on the isosurface.
     *
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     * You can change the settings for the scalar with the {@link ScalarSettings} object.
     *
     * Set to -1 to show no scalars on the isosurface.
     */
    get mapScalarResultId(): number;
    /**
     *
     *
     *
     *
    */
    set mapScalarResultId(mapScalarResultId: number);
    /**
     * The id of the vector result to show on the isosurface. One vector will be shown in each node of the surface.
     *
     * This id must refer to one of the vector results in {@link ModelDirectory.vectorResultArray}.
     * The settings for the vector arrows can be changed with the {@link VectorSettings} object.
     *
     * Set to -1 to show no vectors on the isosurface.
     */
    get mapVectorResultId(): number;
    /**
     *
     *
    */
    set mapVectorResultId(mapVectorResultId: number);
    /**
     * The id of the contour lines result to show on the isosurface.
     *
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarLinesResultArray}.
     *
     * Set to -1 to show no contour lines on the isosurface.
     */
    get mapContourLinesResultId(): number;
    /**
     *
     *
    */
    set mapContourLinesResultId(mapContourLinesResultId: number);
    /**
     * Whether the isosurface should be highlighted.
     */
    get highlight(): boolean;
    /**  */
    set highlight(highlight: boolean);
    /**
     * Opacity of the isosurface. 0.0 means fully transparent (invisible), 1.0 means fully opaque.
     */
    get opacity(): number;
    /**  */
    set opacity(opacity: number);
    /**
     * The color of the isosurface if not showing a result (mapScalarResultId = -1)
     */
    get surfaceColor(): Color3Like;
    /**  */
    set surfaceColor(clr: Color3Like);
    /**
     * If set to true, the isosurface will be computed from only the visible parts. Any part that
     * is not visible will not contribute to the isosurface.
     */
    get computeFromVisibleParts(): boolean;
    set computeFromVisibleParts(visiblePartsOnly: boolean);
    /**
     * Is true if the isosurface is precomputed and cannot be changed
     */
    get isPrecomputed(): boolean;
    /**
     * Gets the settings for this isosurface as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): IsosurfaceProperties;
    /**
     * Applies the settings in the given properties object to this isosurface.
     */
    setFromProperties(props: Partial<IsosurfaceProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of an {@link Isosurface}
 *
 */
export interface IsosurfaceProperties {
    /**
     * See {@link Isosurface.id}
     */
    id: number;
    /**
     * See {@link Isosurface.visible}
     */
    visible: boolean;
    /**
     * See {@link Isosurface.isoValue}
     */
    isoValue: number;
    /**
     * See {@link Isosurface.isoScalarResultId}
     */
    isoScalarResultId: number;
    /**
     * See {@link Isosurface.mapScalarResultId}
     */
    mapScalarResultId: number;
    /**
     * See {@link Isosurface.mapVectorResultId}
     */
    mapVectorResultId: number;
    /**
     * See {@link Isosurface.mapContouLinesrResultId}
     */
    mapContourLinesResultId: number;
    /**
     * See {@link Isosurface.highlight}
     */
    highlight: boolean;
    /**
     * See {@link Isosurface.opacity}
     */
    opacity: number;
    /**
     * See {@link Isosurface.surfaceColor}
     */
    surfaceColor: Color3Like;
    /**
     * See {@link Isosurface.computeFromVisibleParts}
     */
    computeFromVisibleParts: boolean;
    /**
     * See {@link Isosurface.isPrecomputed}
     */
    isPrecomputed: boolean;
}

/**
 * Specification of an isovolume (both parameters and attributes) in a {@link RemoteModel}.
 *
 * Use this object to control the settings and attributes of an isovolume. An isovolume is defined as
 * the combined volume of an element model where a scalar field is between a given minimum and
 * maximum value. The surface of the isovolume is the hull of this volume. Any element on the
 * border of the model (a surface with no neighbor) is also included in the volume if the scalar value on
 * that surface is within the given range.
 *
 * You can map any scalar result onto the isovolume with {@link mapScalarResultId} and
 * any vector result with {@link mapVectorResultId}. The settings for the mapped results can
 * be changed with the {@link ScalarSettings} and {@link VectorSettings} objects.
 *
 * To create an isovolume, use {@link RemoteModel.addIsovolume}.
 *
 * **Example:** Show an isovolume
 *
 *```javascript
 * var modelDir = myModel.modelDirectory;
 *
 * // Add isovolume if we have a scalar result
 * if (modelDir.scalarResultArray.length > 0) {
 *     var iso = myModel.addIsovolume();
 *     iso.isoScalarResultId = modelDir.scalarResultArray[0].id;
 *
 *     iso.minimumIsoValue = 2;
 *     iso.maximumIsoValue = 5;
 *
 *     if (modelDir.scalarResultArray.length > 1) {
 *         iso.mapScalarResultId = modelDir.scalarResultArray[1].id;
 *     } else {
 *         iso.mapScalarResultId = modelDir.scalarResultArray[0].id;
 *     }
 * }
 *
 * // Set model to outline to show the cutting planes
 * myModel.setDrawStyleAllParts(cee.ug.DrawStyle.OUTLINE);
 *```
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/Isovolume.png)
 */
export class Isovolume {
    /**
     *
    */
    private constructor();
    /**
      * The id of the isovolume. This is assigned by the system when you call {@link RemoteModel.addIsovolume}
      * and is used to identify the isovolume.
      */
    get id(): number;
    /**
     * Visibility of the isovolume. Use this to show or hide an isovolume in the 3D Viewer.
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * The minimum scalar value within isovolume.
     */
    get minimumIsoValue(): number;
    /**   */
    set minimumIsoValue(minimumIsoValue: number);
    /**
     * The maximum scalar value within the isovolume.
     */
    get maximumIsoValue(): number;
    /**   */
    set maximumIsoValue(maximumIsoValue: number);
    /**
     * The scalar result to compute the isovolume from. This property is mandatory and must refer to one of
     * the scalar results in {@link ModelDirectory.scalarResultArray}.
     */
    get isoScalarResultId(): number;
    /**   */
    set isoScalarResultId(isoScalarResultId: number);
    /**
     * The id of the scalar result to show on the isovolume.
     *
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     * You can change the settings for the scalar with the {@link ScalarSettings} object.
     *
     * Set to -1 to show no scalars on the isovolume.
     */
    get mapScalarResultId(): number;
    set mapScalarResultId(mapScalarResultId: number);
    /**
     * The id of the vector result to show on the isovolume. One vector will be shown in each node of the surface.
     *
     * This id must refer to one of the vector results in {@link ModelDirectory.vectorResultArray}.
     * The settings for the vector arrows can be changed with the {@link VectorSettings} object.
     *
     * Set to -1 to show no vectors on the isovolume.
     */
    get mapVectorResultId(): number;
    /**
     *
     *
    */
    set mapVectorResultId(mapVectorResultId: number);
    /**
     * Whether the isovolume should be highlighted.
     */
    get highlight(): boolean;
    /**  */
    set highlight(highlight: boolean);
    /**
     * Opacity of the isovolume. 0.0 means fully transparent (invisible), 1.0 means fully opaque.
     */
    get opacity(): number;
    /**  */
    set opacity(opacity: number);
    /**
     * The color of the isovolume if not showing a result (mapScalarResultId = -1)
     */
    get volumeColor(): Color3Like;
    /**  */
    set volumeColor(clr: Color3Like);
    /**
     * If set to true, the isovolume will be computed from only the visible parts. Any part that
     * is not visible will not contribute to the isovolume.
     */
    get computeFromVisibleParts(): boolean;
    set computeFromVisibleParts(visiblePartsOnly: boolean);
    /**
     * Is true if the isovolume is precomputed and cannot be changed
     */
    get isPrecomputed(): boolean;
    /**
     * Gets the settings for this isovolume as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): IsovolumeProperties;
    /**
     * Applies the settings in the given properties object to this isovolume.
     */
    setFromProperties(props: Partial<IsovolumeProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of an {@link Isovolume}
 *
 */
export interface IsovolumeProperties {
    /**
     * See {@link Isovolume.id}
     */
    id: number;
    /**
     * See {@link Isovolume.visible}
     */
    visible: boolean;
    /**
     * See {@link Isovolume.minimumIsoValue}
     */
    minimumIsoValue: number;
    /**
     * See {@link Isovolume.maximumIsoValue}
     */
    maximumIsoValue: number;
    /**
     * See {@link Isovolume.isoScalarResultId}
     */
    isoScalarResultId: number;
    /**
     * See {@link Isovolume.mapScalarResultId}
     */
    mapScalarResultId: number;
    /**
     * See {@link Isovolume.mapVectorResultId}
     */
    mapVectorResultId: number;
    /**
     * See {@link Isovolume.highlight}
     */
    highlight: boolean;
    /**
     * See {@link Isovolume.opacity}
     */
    opacity: number;
    /**
     * See {@link Isovolume.volumeColor}
     */
    volumeColor: Color3Like;
    /**
     * See {@link Isovolume.computeFromVisibleParts}
     */
    computeFromVisibleParts: boolean;
    /**
     * See {@link Isovolume.isPrecomputed}
     */
    isPrecomputed: boolean;
}

/**
 * Settings for mirroring/symmetry in the RemoteModel.
 *
 * Use this class to recreate the full model if the simulation was run on a part of the model
 * to save simulation time exploiting any symmetry in the model.
 *
 * You can access the mirror settings from the {@link RemoteModel.mirrorSettings} property.
 *
 * **Example:** A forging simulation simulating only 1/6'th of the model.
 *
 * CAE model:
 *
 * ![](/images/mirror_single.png)
 *
 * Full model using mirroring with mirrorPassCount = 5:
 *
 * ![](/images/mirror_full.png)
 *
 */
export class MirrorSettings {
    /**
     *
    */
    private constructor();
    /**
     * Enable or disable mirroring/symmetry
     *
     * If enabled, the model will be mirrored according to the given settings
     */
    get enable(): boolean;
    set enable(enable: boolean);
    /**
     * Enable or disable reflective mirroring.
     *
     * If enabled, the mirrored parts will be reflected on plane1/plane2. If disabled, the part will only
     * be rotated into place.
     */
    get reflective(): boolean;
    set reflective(useReflective: boolean);
    /**
     * The number of mirror passes to render.
     */
    get mirrorPassCount(): number;
    set mirrorPassCount(numPasses: number);
    /**
     * Set the first mirror plane to use. This plane will be used for the 1st mirror pass
     */
    get firstPlane(): PlaneLike;
    set firstPlane(plane: PlaneLike);
    /**
     * Set the second mirror plane to use. This plane will be used for the 2nd mirror pass
     */
    get secondPlane(): PlaneLike;
    set secondPlane(plane: PlaneLike);
    /**
     * Set the master mirror plane to use.
     *
     * The master mirror plane will add one final mirroring that mirrors the entire model after doing the
     * given number of mirror passes specified in the first/second plane and the mirrorPassCount.
     */
    get masterPlane(): PlaneLike;
    set masterPlane(plane: PlaneLike);
    /**
     * Gets the settings for this object as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): MirrorSettingsProperties;
    /**
     * Applies the settings in the given properties object to this scalar settings
     */
    setFromProperties(props: Partial<MirrorSettingsProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link MirrorSettingsProperties}
 */
export interface MirrorSettingsProperties {
    /**
     * See {@link MirrorSettings.enable}
     */
    enable: boolean;
    /**
     * See {@link MirrorSettings.reflective}
     */
    reflective: boolean;
    /**
     * See {@link MirrorSettings.mirrorPassCount}
     */
    mirrorPassCount: number;
    /**
     * See {@link MirrorSettings.firstPlane}
     */
    firstPlane: PlaneLike;
    /**
     * See {@link MirrorSettings.secondPlane}
     */
    secondPlane: PlaneLike;
    /**
     * See {@link MirrorSettings.masterPlane}
     */
    masterPlane: PlaneLike;
}

/** @module cee.ug */ /** */
export enum DeriveOperation {
    /** Not derived */
    NOT_DERIVED = 0,
    /** Derive X-component    Scalar result from Vector or Displacement results */
    X_COMPONENT = 1,
    /** Derive Y-component    Scalar result from Vector or Displacement results */
    Y_COMPONENT = 2,
    /** Derive Z-component    Scalar result from Vector or Displacement results */
    Z_COMPONENT = 3,
    /** Length of vector. Scalar result from Vector or Displacement results */
    MAGNITUDE = 4,
    /** Derive XX-component   Scalar result from SymmetricTensor result */
    XX_COMPONENT = 5,
    /** Derive YY-component   Scalar result from SymmetricTensor result */
    YY_COMPONENT = 6,
    /** Derive ZZ-component   Scalar result from SymmetricTensor result */
    ZZ_COMPONENT = 7,
    /** Derive XY-component   Scalar result from SymmetricTensor result */
    XY_COMPONENT = 8,
    /** Derive YZ-component   Scalar result from SymmetricTensor result */
    YZ_COMPONENT = 9,
    /** Derive ZX-component   Scalar result from SymmetricTensor result */
    ZX_COMPONENT = 10,
    /** Derive VonMises       Scalar result from SymmetricTensor result */
    VON_MISES = 11,
    /** Derive 1st principal  Scalar result from SymmetricTensor result */
    FIRST_PRINCIPAL = 12,
    /** Derive 2nd principal  Scalar result from SymmetricTensor result */
    SECOND_PRINCIPAL = 13,
    /** Derive 3rd principal  Scalar result from SymmetricTensor result */
    THIRD_PRINCIPAL = 14,
    /** Derive 1st principal  Vector result from SymmetricTensor result */
    FIRST_PRINCIPAL_VECTOR = 15,
    /** Derive 2nd principal  Vector result from SymmetricTensor result */
    SECOND_PRINCIPAL_VECTOR = 16,
    /** Derive 3rd principal  Vector result from SymmetricTensor result */
    THIRD_PRINCIPAL_VECTOR = 17,
    /** Derive displacement   Vector result from Displacement result */
    DISPLACEMENT_VECTOR = 18,
    /** Unknown derive operation */
    UNKNOWN_DERIVE_OPERATION = 19
}
/**
 * Type of items in a FEM model. Used e.g. for items within a set
 */
export enum ItemType {
    /** Element */
    ELEMENT = 0,
    /** Node */
    NODE = 1,
    /** Element face */
    ELEMENT_FACE = 2,
    /** Element edge */
    ELEMENT_EDGE = 3,
    /** Element node */
    ELEMENT_NODE = 4
}
/**
 * Expose VTFx-specific metadata about the file context
 */
export interface FileInfo {
    vendorName: string;
    exportApplication: string;
}
/**
 * Meta data info for the current simulation
 *
 * The simulation info contains:
 *
 * -   A title
 * -   A description
 * -   A simulation type (structural, fluid, thermal,...)
 * -   A solution type (static, steady state, transient, ...)
 * -   The name of the interface/data provider providing this simulation (if any)
 */
export interface SimulationInfo {
    /**
     * The title of the simulation shown in the model
     */
    readonly title: string;
    /**
     * The description of the simulation shown in the model
     */
    readonly description: string;
    /**
     * The simulation type of the source model.
     *
     * Possible values:
     * Structural, Thermal, Electric, Magnetic, Fluid, Acoustic, Diffusion, Other
     */
    readonly simulationType: string;
    /**
     * The solution type of the source model.
     *
     * Possible values:
     * Static, Steady State, Vibration, Buckling, Transient, Superelement, Frequency response,
     * Complex eigenvalues, Quasi Static, Output, Singular, Other
     */
    readonly solutionType: string;
    /**
     * The name of the interface/data provider of this simulation (if any)
     */
    readonly interfaceName: string;
    /**
     * File specific metadata for VTFx simulation.
     */
    readonly fileInfo: FileInfo;
}
/**
 * Information about a result, including its id and name.
 */
export interface ResultInfo {
    /**
     * The result type  (scalar, vector, displacement)
     */
    readonly resultType: ResultType;
    /**
     * The id of the result.
     */
    readonly id: number;
    /**
     * The persistent string id of the result.
     *
     * This is a persistent ID of the result that will not change between versions of EnvisionWeb, and can thus be used to store setting regarding results.
     * The id of the result might change in future versions of EnvisionWeb, and is only guaranteed to be constant in a given version.
     *
     * Use the {@link ModelDirectory.getResultInfoByIdString} method to find result infos based on the idString.
     */
    readonly idString: string;
    /**
     * The name of the result.
     */
    readonly name: string;
    /**
     * Result position (mapping) of the result
     */
    readonly mapping: ResultMapping;
    /**
     * The unit of the results (if available).
     */
    readonly unit: string;
    /**
     * If the result is derived from a base result (e.g. tensor), baseResultType describes the type of the origin result.
     */
    readonly baseResultType: ResultType;
    /**
     * If the result is derived from a base result (e.g. tensor), baseResultId describes the id of the origin result.
     */
    readonly baseResultId: number;
    /**
     * If the result is derived from a base result (e.g. tensor), deriveOperation describes how the result was derived from the base result.
     */
    readonly deriveOperation: DeriveOperation;
    /**
     * If non empty, the ID of the result calculator producing this result
     */
    readonly resultCalculatorId: string;
}
/**
 * Information about an available sets. A set is a group of unique items, but the items can span parts and geometries.
 *
 * All items will be of the same type. The following set types are supported:
 *
 *  - Element sets
 *  - Node sets
 *  - Element face sets
 *  - Element edge sets
 *  - Element node sets
 */
export interface SetInfo {
    /**
     * The unique ID of the set, used in the model spec to specify visible sets
     */
    readonly id: number;
    /**
     * The type of items in the set. All set items are of the same type
     */
    readonly itemType: ItemType;
    /**
    * The name of the set.
    */
    readonly name: string;
    /**
     * The description of the set.
     */
    readonly description: string;
}
/**
 * The id and name of a part, and the index of the geometry it belongs to.
 *
 * Parts are uniquely identified by the combination of geometry index and part id.
 */
export interface PartInfo {
    /**
     * The zero-based index of the geometry the part belongs to.
     * In most cases there is only one geometry and this index will be zero.
     */
    readonly geometryIndex: number;
    /**
     * The unique (within the geometry) id of the part. Part ids are >= 0.
     */
    readonly partId: number;
    /**
     * The name of the part
     */
    readonly name: string;
    /**
     * True if the part is a boundary condition part
     */
    readonly boundaryCondition: boolean;
    /**
     * The id of the parent part. -1 if none
     */
    readonly parentPartId: number;
    /**
     * Additional key,value info describing the part
     */
    readonly partDataArr: ReadonlyArray<{
        key: string;
        value: string;
    }>;
}
/**
 * Information about a data state
 *
 * States are uniquely identified by the id.
 */
export interface StateInfo {
    /**
     * The id of the state. This id is used in {@link ModelSpec.stateIdArray} to specify which state(s) to show. Ids are >= 0.
     */
    readonly id: number;
    /**
     * The name of the state
     */
    readonly name: string;
    /**
     * The reference value of the state. Often simulation time, but can also be frequency for frequency domain simulations.
     */
    readonly referenceValue: number;
    /**
     * Defines which scalar results are available in this state. Empty = all results are available.
     */
    readonly scalarResultIdArr: number[];
    /**
     * Defines which scalar results are available in this state. Empty = all results are available.
     */
    readonly vectorResultIdArr: number[];
    /**
     * Defines which scalar results are available in this state. Empty = all results are available.
     */
    readonly displacementResultIdArr: number[];
}
/**
 * Information about a data state group.
 *
 * Each group contains an array of state ids, {@link stateIdArr}, which can be set in {@link ModelSpec.stateIdArray}.
 */
export interface StateGroupInfo {
    /**
     * The id of the state group.
     */
    readonly id: number;
    /**
     * The name of the state group.
     */
    readonly name: string;
    /**
     * All the state ids of the state group.
     */
    readonly stateIdArr: number[];
}
/**
 * The id and name of a case in the VTFx file
 */
export interface VTFxCaseInfo {
    /**
     * The id of the case
     */
    readonly caseId: number;
    /**
     * The name of the case
     */
    readonly name: string;
    /**
     * The description of the VTFx case.
     */
    readonly description: string;
}
/**
 * The model directory contains a table of contents of what is available in the current CAE
 * analysis. It has a list of all states/time steps, results and part infos in the model.
 *
 * The model directory can be used to populate a UI with the available states and results. It is
 * used by property accessors when specifying results and states (e.g. in the {@link ModelSpec}) to verify that
 * the input is correct.
 *
 * You can access the model directory using {@link RemoteModel.modelDirectory}.
 */
export class ModelDirectory {
    /**
     * Meta data info for the current simulation
     */
    readonly simulationInfo: SimulationInfo;
    /**
     * An array of the available states in the model. The id's are unique and >= 0. The names describe the states/time steps.
     * Use the Ids when specifying state ids in the {@link ModelSpec}.
     */
    readonly stateInfoArray: ReadonlyArray<StateInfo>;
    /**
     * An array of the available state groups in the model. The id's are unique and >= 0. The names describe the group.
     * Use the property {@link StateGroupInfo.stateIdArr} when specifying state ids in the {@link ModelSpec.stateIdArray}.
     */
    readonly stateGroupInfoArray: ReadonlyArray<StateGroupInfo>;
    /**
     * An array of the available scalar results in the model. The id's are unique and >= 0. The names describe the results.
     * Use the Ids when specifying scalar result ids in the {@link ModelSpec}, {@link CuttingPlane CuttingPlanes}, {@link Isosurface Isosurfaces}, {@link Isovolume Isovolumes} or
     * {@link ParticleTraceGroup ParticleTraceGroups}.
     */
    readonly scalarResultArray: ReadonlyArray<ResultInfo>;
    /**
     * An array of the available vector results in the model. The id's are unique and >= 0. The names describe the results.
     * Use the Ids when specifying vector result ids in the {@link ModelSpec}, {@link CuttingPlane CuttingPlanes}, {@link Isosurface Isosurfaces}, {@link Isovolume Isovolumes} or
     * {@link ParticleTraceGroup ParticleTraceGroups}.
     */
    readonly vectorResultArray: ReadonlyArray<ResultInfo>;
    /**
     * An array of the available displacement results in the model. The id's are unique and >= 0. The names describe the results.
     * Use the Ids when specifying the displacement result id in the {@link ModelSpec}.
     */
    readonly displacementResultArray: ReadonlyArray<ResultInfo>;
    /**
     * An array of the available element sets  in the model. The id's are unique and >= 0. The names describe the set.
     * Use the Ids when specifying the visible sets in the {@link ModelSpec}.
     */
    readonly setInfoArray: ReadonlyArray<SetInfo>;
    /**
     * Whether the model has a rigid body transformation result.
     */
    readonly hasTransformationResult: boolean;
    /**
     * An array of the parts in the model. See {@link PartInfo} for more information about parts.
     */
    readonly partInfoArray: ReadonlyArray<PartInfo>;
    /**
     * An array of cases present in the VTFx file. Use the format modelKey|caseId to open a specific case from a VTFx file.
     */
    readonly vtfxCaseInfoArray: ReadonlyArray<VTFxCaseInfo>;
    /**
     *
    */
    private constructor();
    /**
     * Returns an array of all state ids in the model.
     *
     * Useful for setting up an animation over all states.
     */
    getAllStateIds(): number[];
    /**
     * Returns the name of the state with the given id, or null if the id is invalid.
     */
    getStateNameById(id: number): string | null;
    /**
     * Returns the reference value of the state with the given id, or undefined if the id is invalid.
     */
    getStateReferenceValueById(id: number): number | undefined;
    /**
     * Returns the name of the scalar result with the given id, or null if the id is invalid.
     */
    getScalarNameById(id: number): string | null;
    /**
     * Returns the name of the vector result with the given id, or null if the id is invalid.
     */
    getVectorNameById(id: number): string | null;
    /**
     * Returns the name of the displacement result with the given id, or null if the id is invalid.
     */
    getDisplacementNameById(id: number): string | null;
    /**
     * Returns the name of the element set with the given id, or null if the id is invalid.
     */
    getSetNameById(id: number): string | null;
    /**
     * Returns the name of the part with the given geometryIndex/partId, or null if the geometryIndex/id
     * pair is invalid.
     */
    getPartNameById(geometryIndex: number, id: number): string | null;
    /**
     * Find the result info of the result with the given type and idString.
     * Returns null when no match is found.
     */
    getResultInfoByIdString(resultType: ResultType, idString: string): ResultInfo | null;
    /**
     * Find the result id of the result with the given type and `idString`.
     *
     * Returns -1 if the result `idString` was not found.
     */
    getResultIdByIdString(resultType: ResultType, idString: string): number;
    /**
     * Find the idString of the result with the given type and result id.
     *
     * Returns null if `id` was not found.
     */
    getResultIdStringById(resultType: ResultType, id: number): string | null;
    /**
     * Returns true if the given state contains the given scalar result id
     */
    hasScalarResult(stateId: number, resultId: number): boolean;
    /**
     * Returns true if the given state contains the given vector result id
     */
    hasVectorResult(stateId: number, resultId: number): boolean;
    /**
     * Returns true if the given state contains the given scalar result id
     */
    hasDisplacementResult(stateId: number, resultId: number): boolean;
}

/**
 * Mode shape animation type
 */
export enum ModeShapeAnimationType {
    /**
     * Animate from original position to the displaced position: V0 ... VD
     */
    QUARTER = 0,
    /**
     * Animate from original position to the displaced position and back again: V0 ... VD ... V0
     */
    HALF = 1,
    /**
     * Animate from the original position to the displaced position and back again,
     * then to the negative displacement and back: V0 ... VD ... V0 ... -VD ... V0
     */
    FULL = 2
}
/**
 * Specification of what to show in the 3D viewer.
 *
 * The ModelSpec controls what to show in the 3D Viewer. You specify which state(s)/time step(s) to
 * show and which results to show. You can also specify a mode-shape animation.
 *
 * The {@link ModelDirectory} contains the list of available results and states that can be set in the {@link ModelSpec}.
 * When calling changing state or result properties in this class it is checked against the
 * {@link ModelDirectory} and an exception is thrown if any of the ids are invalid.
 *
 * **Example:** Show the last state with a scalar result as filled contours.
 *
 * ```javascript
 * // Get the model and the model directory from the RemoteModel
 * var modelDir = myModel.modelDirectory;
 * var modelSpec = myModel.modelSpec;
 *
 * // Show the last state in the analysis
 * modelSpec.stateIdArray = [modelDir.stateInfoArray[modelDir.stateInfoArray.length - 1].id];
 *
 * // Show the first scalar as filled contours (if any)
 * if (modelDir.scalarResultArray.length > 0) {
 *     modelSpec.fringesResultId = modelDir.scalarResultArray[0].id;
 * }
 * ```
 */
export class ModelSpec {
    /**
     *
    */
    private constructor();
    /**
     * The Ids of the states to show. An animation will be created if there is more than one item in the array.
     *
     * At least one state id must be specified in order to show the model.
     */
    get stateIdArray(): ReadonlyArray<number>;
    set stateIdArray(stateIdsArr: ReadonlyArray<number>);
    /**
     * The id of the scalar result to show as textured fringes (filled contours) on the model.
     * Use the {@link ScalarSettings} object to control how the scalar will be shown (range, color scheme, number of levels)
     *
     * Set to -1 (default) to show no scalars on the model.
     *
     * Note: The scalar fringes result Id can be overridden per part with the {@link setOverridePartFringesResultId} method.
     */
    get fringesResultId(): number;
    set fringesResultId(resultId: number);
    /**
     * Returns the id of the scalar result shown on the given part. Will return fringesResultId if no override result was
     * specified for the given part.
     */
    getEffectiveFringesResultId(geometryIndex: number, partId: number): number;
    /**
     * Returns the result id that is specified to override any global setting on the given part.
     * If no override is provided, it will return -1.
     */
    getOverridePartFringesResultId(geometryIndex: number, partId: number): number;
    /**
     * Specify to show the given scalar result on the given part as scalar fringes.
     *
     * This overrides any global fringes setting for the given part.
     */
    setOverridePartFringesResultId(geometryIndex: number, partId: number, fringesId: number): void;
    /**
     * Remove any overridden scalar fringes result ids for any parts.
     *
     * All parts will after this follow the global setting ({@link ModelSpec.fringesResultId})
     */
    removeAllOverridePartFringesResultIds(): void;
    /**
     * The array of vector result ids to show as vector arrows on the model surface.
     * Use the {@link VectorSettings} object to control how the vectors will be shown (color, scaling, filtering, clamping)
     *
     * Set to [] (default) to show no vectors on the model. [-1] is interpreted as [] for convenience.
     */
    get vectorResultIdArray(): ReadonlyArray<number>;
    set vectorResultIdArray(resultIdArray: ReadonlyArray<number>);
    /**
     * The id of the displacement result to use. A displacement result is a per node result that displaces the nodes in the model
     * in every time step without redefining the elements.
     *
     * Use the {@link DisplacementSettings} object to control the scaling of the displacements.
     *
     * Set to -1 to show no displacements in the model.
     */
    get displacementResultId(): number;
    set displacementResultId(resultId: number);
    /**
     * Whether the rigid body transformation result should be used (if present).
     *
     * Default is true.
     */
    get useTransformationResult(): boolean;
    set useTransformationResult(useTransformationResult: boolean);
    /**
     * Specifies that the complement of the current visible sets will be shown.
     *
     * If this option is enabled, only the elements that are NOT present in any of the visible sets
     * will be shown.
     */
    get showComplementOfVisibleSets(): boolean;
    set showComplementOfVisibleSets(showComplement: boolean);
    /**
     * If the array is not empty, the given set ids will be used to define which elements are visible.
     * The union of the elements in the specified visible sets will be considered visible.
     *
     * You can show the complement of the visible set by setting the showComplementOfVisibleSets property to true.
     *
     * Set to [] (default) to disable set filtering on the model. [-1] is interpreted as [] for convenience.
     */
    get visibleSetIdArray(): ReadonlyArray<number>;
    set visibleSetIdArray(setIdArray: ReadonlyArray<number>);
    /**
     * The number of frames to use for a mode shape animation.
     *
     * A mode shape animation is an animation where the displacements of each node is interpolated between the undisplaced and the
     * displaced positions. To setup a mode shape animation we recommend to have a displacement result specified in
     * {@link displacementResultId} and exactly one state specified in {@link stateIdArray}.
     *
     * Set to 0 (default) to not use mode shape animation.
     *
     * Note: Although we support switching results in the middle of a mode shape animation, we recommend to setup
     * the desired (scalar, vector, displacement) results first and then setting the {@link modeShapeFrameCount}.
     */
    get modeShapeFrameCount(): number;
    set modeShapeFrameCount(frameCount: number);
    /**
     * The type of mode shape animation to create: Quarter, Half or Full (default).
     */
    get modeShapeAnimationType(): ModeShapeAnimationType;
    set modeShapeAnimationType(animType: ModeShapeAnimationType);
    /**
     * Specifies if the scalars should be interpolated during a mode-shape animation or not.
     */
    get modeShapeInterpolateScalars(): boolean;
    set modeShapeInterpolateScalars(interpolate: boolean);
    /**
     * Gets the settings for this model spec as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): ModelSpecProperties;
    /**
     * Applies the settings in the given properties object to this model spec.
     */
    setFromProperties(props: Partial<ModelSpecProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link ModelSpec}
 */
export interface ModelSpecProperties {
    /**
     * See {@link ModelSpec.stateIdArray}
     */
    stateIdArray: ReadonlyArray<number>;
    /**
     * See {@link ModelSpec.fringesResultId}
     */
    fringesResultId: number;
    /**
     * See {@link ModelSpec.vectorResultIdArray}
     */
    vectorResultIdArray: ReadonlyArray<number>;
    /**
     * See {@link ModelSpec.displacementResultId}
     */
    displacementResultId: number;
    /**
     * See {@link ModelSpec.useTransformationResult}
     */
    useTransformationResult: boolean;
    /**
     * See {@link ModelSpec.showComplementOfVisibleSets}
     */
    showComplementOfVisibleSets: boolean;
    /**
     * See {@link ModelSpec.visibleSetIdArray}
     */
    visibleSetIdArray: ReadonlyArray<number>;
    /**
     * See {@link ModelSpec.modeShapeFrameCount}
     */
    modeShapeFrameCount: number;
    /**
     * See {@link ModelSpec.modeShapeAnimationType}
     */
    modeShapeAnimationType: ModeShapeAnimationType;
    /**
     * See {@link ModelSpec.modeShapeInterpolateScalars}
     */
    modeShapeInterpolateScalars: boolean;
    /**
     * See {@link ModelSpec.getOverridePartFringesResultId}
     */
    overridePartFringesSpecArr: ReadonlyArray<{
        geometryIndex: number;
        partId: number;
        resultId: number;
    }>;
}

/** @module cee.ug */ /** */
/**
 * Model color source. This will determine how to color each face of the model if no fringes results are used.
 */
export enum ModelColorSource {
    /**
     * Use part colors (default)
     */
    PART = 0,
    /**
     * Color by sets
     */
    SET = 1,
    /**
     * Color by element types
     */
    ELEMENT_TYPE = 2,
    /**
     * Color by the first user property (index 0)
     */
    USER_PROPERTY_0 = 3,
    /**
     * Color by the second user property (index 1)
     */
    USER_PROPERTY_1 = 4,
    /**
     * Color by the third user property (index 2)
     */
    USER_PROPERTY_2 = 5
}
/**
 * Various settings for the RemoteModel.
 */
export class ModelSettings {
    /**
     *
    */
    private constructor();
    /**
     * When enabled, only the first order element nodes will be considered.
     * For example, Quad8 is visualized as Quad4, dropping the mid-nodes.
     */
    get useFirstOrderElementNodesOnly(): boolean;
    set useFirstOrderElementNodesOnly(useFirstOrderElementNodesOnly: boolean);
    /**
     * Specify how to color the parts if no fringesResults are used.
     *
     * This will determine how to color each face of the model if no fringesResults are used.
     * Default is PART (use part colors).
     */
    get modelColorSource(): ModelColorSource;
    set modelColorSource(colorSource: ModelColorSource);
    /**
     * The transformation matrix to use for this model.
     *
     * If specified, all parts in the model will be transformed by this matrix. This can be useful for scene
     * composition. The default is null.
     */
    get transformationMatrix(): Mat4 | null;
    set transformationMatrix(transformationMatrix: Mat4 | null);
    /**
     * Gets the settings for this object as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): ModelSettingsProperties;
    /**
     * Applies the settings in the given properties object to this scalar settings
     */
    setFromProperties(props: Partial<ModelSettingsProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link ModelSettings}
 */
export interface ModelSettingsProperties {
    /**
     * See {@link ModelSettings.useFirstOrderElementNodesOnly}
     */
    useFirstOrderElementNodesOnly: boolean;
    /**
     * See {@link ModelSettings.modelColorSource}
     */
    modelColorSource: ModelColorSource;
    /**
     * See {@link ModelSettings.transformationMatrix}
     */
    transformationMatrix: Mat4 | null;
}

/** @module cee.ug */ /** */
/**
 * Parameters for Massed Particle Traces.
 *
 * If these parameters are specified in the {@link ParticleTraceGroup.massedParticleParameters} property,
 * the particle trace will be computed based on a massed particle formulation using the given
 * parameters.
 *
 * To compute normal steam lines (massless particles), set {@link ParticleTraceGroup.massedParticleParameters}
 * to undefined (this is the default setting).
 */
export interface MassedParticleParameters {
    /**
     * ID of scalar result for fluid density
     */
    fluidDensityResultId: number;
    /**
     * The constant fluid density to use if the fluidDensityResultId is not set (-1)
     */
    constantFluidDensity: number;
    /**
     * ID of scalar result for fluid molecular viscosity
     */
    fluidViscosityResultId: number;
    /**
     * The constant fluid viscosity to use if the fluidViscosityResultId is not set (-1)
     */
    constantFluidViscosity: number;
    /**
     * Particle density
     */
    density: number;
    /**
     * Particle radius
     */
    radius: number;
    /**
     * Gravity (e.g. <0,0,-9.81> for normal earth gravity if in SI system)
     */
    gravity: Vec3Like;
    /**
     * Coefficient of restitution _(Currently not in use)_
     */
    restitutionCoefficient?: number;
}
/**
 * The visualization style to use for particle traces.
 */
export enum ParticleTraceVisualizationStyle {
    /**
     * Draw traces as cylinders
     */
    CYLINDERS = 0,
    /**
     * Draw traces as spheres
     */
    SPHERES = 1,
    /**
     * Draw traces as comets
     */
    COMETS = 2
}
/**
 * Specification of a particle trace group (both parameters and attributes) in a {@link RemoteModel}.
 *
 * To visualize features of a vector field, it is possible to define streamlines: the paths of massless
 * particles through the flow. Streamlines can be computed based on the specification of single points.
 * Animating the movement of particles along these streamlines gives a powerful and direct tool for visualizing
 * the features of a flow.
 *
 * Particle traces are defined by a vector result specifying the vector field and an array of trace seed points.
 * The particles traces use 3D primitives such as cylinders, spheres, or comets to visualize the traces.
 * A scalar result can be mapped as fringes onto these primitives.
 *
 * Particle traces can be animated. All particle trace groups must have the same number of animation steps.
 * You specify this with {@link Animation.particleTraceAnimationStepCount}. You can start the animation with
 * {@link Animation.runParticleTraceAnimation}.
 *
 * To create a particle trace group, use {@link RemoteModel.addParticleTraceGroup}.
 *
 * **Example:** Show a grid of traces
 *
 *```javascript
 * var modelDir = myModel.modelDirectory;
 *
 * // Create a grid of 10x10 points to use a seed points
 * var center = new cee.Vec3(-0.017, -0.00726, 0.0016);
 * var seedPoints = cee.ug.ParticleTraceUtils.computeGridPoints(center,
 *                  new cee.Vec3(1,0,0), 10, 10, 0.0005);
 *
 * // Create the particle trace group
 * var ptGroup = myModel.addParticleTraceGroup();
 * ptGroup.seedPointArray = seedPoints;
 * ptGroup.vectorResultId = modelDir.vectorResultArray[0].id;
 * ptGroup.mapScalarResultId = modelDir.scalarResultArray[0].id;
 * ptGroup.radius = 0.00015;
 *
 * // Set model to outline to show the cutting planes
 * myModel.setDrawStyleAllParts(cee.ug.DrawStyle.OUTLINE);
 *```
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/ParticleTraceGroup.png)
 */
export class ParticleTraceGroup {
    /**
     *
    */
    private constructor();
    /**
     * The id of the particle trace group. This is assigned by the system when you call {@link RemoteModel.addParticleTraceGroup}
     * and is used to identify the group.
     */
    get id(): number;
    /**
     * Visibility of the particle trace group. Use this to show or hide a particle trace group in the 3D Viewer.
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * An array of seed points. Each point will result in a particle trace going through the point. If {@link traceBothDirections}
     * is set to true, the trace will be computed both forwards and backwards from this point. If it set to false, only the forward
     * computation will be done. All traces share the same settings, as defined by other properties of the {@link ParticleTraceGroup}.
     *
     * You can use the {@link ParticleTraceUtils.computeGridPoints} static function to generate a grid of points based on a point and normal.
     */
    get seedPointArray(): ReadonlyArray<Vec3Like>;
    /**
     *
     *
    */
    set seedPointArray(pointArr: ReadonlyArray<Vec3Like>);
    /**
     * If set to true, the trace will be computed both forwards and backwards from the seed point(s).
     *
     * If set to false, the trace will only be computed forwards from the seed point(s).
     */
    get traceBothDirections(): boolean;
    /**  */
    set traceBothDirections(bothDirections: boolean);
    /**
     * Sets the maximum number of points to compute for this group
     *
     * This controls the maximum number of increments that will be computed for each trace in this group.
     */
    get maximumNumberOfPointsToCompute(): number;
    set maximumNumberOfPointsToCompute(ratio: number);
    /**
     * The ratio length relative to the frame bounding box to test when moving out of the part
     *
     * This controls how far to extrapolate the particle trace when leaving a part and entering another part
     * The Ratio is given as a fraction of the bounding box of the current frame.
     */
    get extrapolateRatioLength(): number;
    set extrapolateRatioLength(ratio: number);
    /**
     * The vector result to compute the traces in. This property is mandatory and must refer to one of the vector
     * results in {@link ModelDirectory.vectorResultArray}.
     */
    get vectorResultId(): number;
    /**  */
    set vectorResultId(resultId: number);
    /**
     * The id of the scalar result to show on the particle traces.
     *
     * This id must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     * You can change the settings for the scalar with the {@link ScalarSettings} object.
     *
     * Set to -1 to show no scalars on the traces. In this case the value of {@link color} will be applied.
     */
    get mapScalarResultId(): number;
    /**
     *
     *
    */
    set mapScalarResultId(resultId: number);
    /**
     * The visualization type to use for the particle traces. This can be set to cylinders, spheres or comets.
     */
    get visualizationStyle(): ParticleTraceVisualizationStyle;
    /**  */
    set visualizationStyle(style: ParticleTraceVisualizationStyle);
    /**
     * The color of the particle traces. This property only applies if {@link mapScalarResultId} is set to -1.
     *
     * The default is white (1,1,1)
     */
    get color(): Color3Like;
    /**  */
    set color(clr: Color3Like);
    /**
     * The radius of the particle trace geometry (cylinder, sphere, comet), in world coordinates.
     *
     * The default is 0.005 of the extent of the bounding box.
     */
    get radius(): number;
    /**  */
    set radius(radius: number);
    /**
     * Spheres and comets are emitted at regular intervals. This value specifies how many pulses there should be
     * in the model.
     *
     * The default is 5.
     */
    get pointSamplingPulseCount(): number;
    /**  */
    set pointSamplingPulseCount(numPulses: number);
    /**
     * The length of the tail of the comets. It is specified in time and is a fraction of the global
     * total time range for all particles in this group.
     *
     * For example, if the total trace time is 2, and the relativeCometLength is 0.01, then the length of the tail will be
     * 0.02.
     *
     * The default is 0.1
     */
    get relativeCometLength(): number;
    set relativeCometLength(relLength: number);
    /**
     * Set whether the particle traces in this group should ignore clipping.
     *
     * The default is false, which means that the traces will be clipped.
     */
    get ignoreClipping(): boolean;
    set ignoreClipping(ignore: boolean);
    /**
     * Is true if the particle trace group is precomputed and cannot be changed
     */
    get isPrecomputed(): boolean;
    /**
     * Massed particle trace parameters.
     *
     * If these paramers are set (not undefined), the particle traces will be computed based on
     * massed particles with the given properties.
     */
    get massedParticleParameters(): MassedParticleParameters | undefined;
    set massedParticleParameters(params: MassedParticleParameters | undefined);
    /**
     * Gets the settings for this particle trace group as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): ParticleTraceGroupProperties;
    /**
     * Applies the settings in the given properties object to this particle trace group
     */
    setFromProperties(props: Partial<ParticleTraceGroupProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link ParticleTraceGroup}
 */
export interface ParticleTraceGroupProperties {
    /**
     * See {@link ParticleTraceGroup.id}
     */
    id: number;
    /**
     * See {@link ParticleTraceGroup.visible}
     */
    visible: boolean;
    /**
     * See {@link ParticleTraceGroup.seedPointArray}
     */
    seedPointArray: ReadonlyArray<Vec3Like>;
    /**
     * See {@link ParticleTraceGroup.traceBothDirections}
     */
    traceBothDirections: boolean;
    /**
     * See {@link ParticleTraceGroup.maximumNumberOfPointsToCompute}
     */
    maximumNumberOfPointsToCompute: number;
    /**
     * See {@link ParticleTraceGroup.extrapolateRatioLength}
     */
    extrapolateRatioLength: number;
    /**
     * See {@link ParticleTraceGroup.vectorResultId}
     */
    vectorResultId: number;
    /**
     * See {@link ParticleTraceGroup.mapScalarResultId}
     */
    mapScalarResultId: number;
    /**
     * See {@link ParticleTraceGroup.visualizationStyle}
     */
    visualizationStyle: ParticleTraceVisualizationStyle;
    /**
     * See {@link ParticleTraceGroup.color}
     */
    color: Color3Like;
    /**
     * See {@link ParticleTraceGroup.radius}
     */
    radius: number;
    /**
     * See {@link ParticleTraceGroup.pointSamplingPulseCount}
     */
    pointSamplingPulseCount: number;
    /**
     * See {@link ParticleTraceGroup.relativeCometLength}
     */
    relativeCometLength: number;
    /**
     * See {@link ParticleTraceGroup.ignoreClipping}
     */
    ignoreClipping: boolean;
    /**
     * See {@link ParticleTraceGroup.isPrecomputed}
     */
    isPrecomputed: boolean;
    /**
     * See {@link ParticleTraceGroup.massedParticleParameters}
     */
    massedParticleParameters?: {
        fluidDensityResultId: number;
        constantFluidDensity: number;
        fluidViscosityResultId: number;
        constantFluidViscosity: number;
        density: number;
        radius: number;
        gravity: Vec3Like;
        restitutionCoefficient?: number;
    };
}

/** @module cee.ug */ /** */
/**
 * Helper functions for particle traces
 */
export class ParticleTraceUtils {
    /**
     * Computes a grid of points based on the given point and normal and returns the array of points
     *
     * Useful for generating particle trace seed points. All grid points will be in the plane specified by the
     * given center and normal, centered around the center.
     *
     * @param center The center of the grid of generated points
     * @param normal The normal of the surface which the grid points will be on.
     * @param numU Number of grid point in the U direction.
     * @param numV Number of grid points in the V direction.
     * @param groupSpacing The distance between each point in the grid.
     *
     * @returns An array of Vec3 points forming a grid as specified. The grid will contain numU*numV points.
     */
    static computeGridPoints(center: Vec3Like, normal: Vec3Like, numU: number, numV: number, groupSpacing: number): Vec3[];
    /**
     * Compute seed points based on the centroids of the visible element surfaces of a part.
     *
     * @param pointArr The result of a QueryPartSurfacePositions
     * @param normalArr Per point normals. The normal is used to nudge the seed point a bit in the opposite direction of the normal.
     *                  This is to cater for the seed point being inside the volume and not outside due to numeric precision.
     * @param modelBoundingBox Model bounding box. Used to figure out how much to nudge the seed points to be inside the volume
     * @param planeFilter If a plane is passed in this parameter, only centroids that are on or very close to this plane will be used.
     *
     * @returns An array of Vec3 points.
     */
    static seedPointsFromPointsAndNormals(pointArr: ArrayLike<number>, normalArr: ArrayLike<number>, modelBoundingBox: BoundingBox, planeFilter?: Plane): Vec3[];
}

/**
 * Part draw style. Specifies how parts should be rendered.
 */
export enum DrawStyle {
    /**
     * Render the part as surface.
     */
    SURFACE = 0,
    /**
     * Render the part as surface with an overlay of the element mesh. Note that this is not the triangle mesh,
     * but the actual FEA element mesh.
     */
    SURFACE_MESH = 1,
    /**
     * Render the part as surface with mesh lines on the feature edges (edges where the angle between two elements
     * are larger that 60 degrees).
     */
    SURFACE_OUTLINE_MESH = 2,
    /**
     * Render the edges of the elements as lines. Note that this is not the triangle edges but the FEA element edges.
     */
    LINES = 3,
    /**
     * Render the nodes of the part as points.
     */
    POINTS = 4,
    /**
     * Render the part as outline. Lines will be drawn on the feature edges (edges where the angle between two elements
     * are larger that 60 degrees).
     */
    OUTLINE = 5,
    /**
     * Render the part as lines, but use the depth buffer to remove lines that are obscured by the model itself.
     */
    HIDDEN_LINES_REMOVED = 6
}
/**
 * Specification of the visual appearance of a part in a RemoteModel
 *
 * Use this object to control how the part will be rendered in the 3D viewer. You can set whether the part is {@link visible},
 * the {@link drawStyle}, {@link color}, {@link opacity}, and if the part should be {@link smooth} or flat shaded. You can also
 * set {@link showFringes} to specify if the part should show the current scalar result (if a scalar result is specified in the {@link ModelSpec})
 * and set {@link showVectors} to specify if vector arrows should be drawn for the surface of this part (if a vector result is specified in the
 * {@link ModelSpec}).
 *
 * You can access PartSettings objects with {@link RemoteModel.getPartSettingsAt}.
 *
 * **Example:** Show all parts as transparent
 *
 * ```javascript
 * for (var i = 0; i < myModel.partCount; ++i) {
 *     var partSettings = myModel.getPartSettingsAt(i);
 *     partSettings.drawStyle = cee.ug.DrawStyle.SURFACE;
 *     partSettings.opacity = 0.5;
 * }
 * ```
 *
 * or
 *
 * ```javascript
 * for (var ps of myModel.getPartSettingsArray()) {
 *     ps.drawStyle = cee.ug.DrawStyle.SURFACE;
 *     ps.opacity = 0.5;
 * }
 * ```
 */
export class PartSettings {
    /**
     *
    */
    private constructor();
    /**
     * The zero-based geometryIndex of the part. A RemoteModel might have more than one geometry, but in most cases there is only one.
     * The combination of geometryIndex and partId uniquely identifies the part.
     */
    get geometryIndex(): number;
    /**
     * The id of the part. The id is >=0 and unique within the part's geometry.
     * The combination of geometryIndex and partId uniquely identifies the part.
     */
    get partId(): number;
    /**
     * Visibility of the part. Use this to show or hide a part in the 3D Viewer.
     */
    get visible(): boolean;
    /**  */
    set visible(visible: boolean);
    /**
     * Whether the part should be highlighted.
     */
    get highlight(): boolean;
    /**
     *
     *
    */
    set highlight(highlight: boolean);
    /**
     * The specification of how to render the part (surface, lines, points, mesh, etc).
     */
    get drawStyle(): DrawStyle;
    /**  */
    set drawStyle(drawStyle: DrawStyle);
    /**
     * The color of the part.
     */
    get color(): Color3Like;
    /**  */
    set color(clr: Color3Like);
    /**
     * The opacity of the part. 1.0 is fully opaque, 0.0 if fully transparent (invisible).
     */
    get opacity(): number;
    /**  */
    set opacity(opacity: number);
    /**
     * Flag controlling the shading model of the part.
     *
     * If true, smooth shading will be used for the part, where it is rendered with a smoothed out surface with
     * a per pixel lighting. If false, a flat shading rendering will be applied where the surface of an element
     * is rendered with the same color.
     */
    get smooth(): boolean;
    /**
     *
     *
     */
    set smooth(smooth: boolean);
    /**
     * Whether scalar fringes (filled contours) should be shown on this part. This
     * flag only applies if the {@link ModelSpec.fringesResultId} is set to a valid scalar result id.
     */
    get showFringes(): boolean;
    /**  */
    set showFringes(show: boolean);
    /**
     * Whether vector arrows should be rendered on the surface of this part. This
     * flag only applies if the {@link ModelSpec.vectorResultIdArray} is set to valid vector result id(s).
     */
    get showVectors(): boolean;
    /**  */
    set showVectors(show: boolean);
    /**
     * The eye lift mode to use for this part.
     *
     * Eye lift can be used when facing z fighting issues (triangles rendered in the same plane).
     * By applying eye lift to one part, it will be moved slightly towards the eye, resolving the
     * z fighting issues. The current version offers 3 eye lift factors to choose from.
     */
    get eyeLift(): EyeLift;
    set eyeLift(mode: EyeLift);
    /**
     * Disable mirroring for this part.
     *
     * If set to true, this part will not be included in the mirroring of the model.
     */
    get disableMirroring(): boolean;
    set disableMirroring(disable: boolean);
    /**
     * Disables element set filtering for this part. See {@link ModelSpec.visibleSetIdArray}
     */
    get disableElementSetFiltering(): boolean;
    set disableElementSetFiltering(disable: boolean);
    /**
     * Disables feature extraction for this part. It will be excluded when computing e.g. isosurfaces.
     */
    get disableFeatureExtraction(): boolean;
    set disableFeatureExtraction(disable: boolean);
    /**
     * Disables element expansion for this part. Beams will be shown as lines regardless of if they have
     * cross section data defined or not.
     */
    get disableExpandElements(): boolean;
    set disableExpandElements(disable: boolean);
    /**
     * Gets the settings for this part as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): PartSettingsProperties;
    /**
     * Applies the settings in the given properties object to this part
     */
    setFromProperties(props: Partial<PartSettingsProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link PartSettings}
 */
export interface PartSettingsProperties {
    /**
     * See {@link PartSettings.geometryIndex}
     */
    geometryIndex: number;
    /**
     * See {@link PartSettings.partId}
     */
    partId: number;
    /**
     * See {@link PartSettings.visible}
     */
    visible: boolean;
    /**
     * See {@link PartSettings.highlight}
     */
    highlight: boolean;
    /**
     * See {@link PartSettings.drawStyle}
     */
    drawStyle: DrawStyle;
    /**
     * See {@link PartSettings.color}
     */
    color: Color3Like;
    /**
     * See {@link PartSettings.opacity}
     */
    opacity: number;
    /**
     * See {@link PartSettings.smooth}
     */
    smooth: boolean;
    /**
     * See {@link PartSettings.showFringes}
     */
    showFringes: boolean;
    /**
     * See {@link PartSettings.showVectors}
     */
    showVectors: boolean;
    /**
     * See {@link PartSettings.eyeLift}
     */
    eyeLift: EyeLift;
    /**
     * See {@link PartSettings.disableMirroring}
     */
    disableMirroring: boolean;
    /**
     * See {@link PartSettings.disableElementSetFiltering}
     */
    disableElementSetFiltering: boolean;
    /**
     * See {@link PartSettings.disableFeatureExtraction}
     */
    disableFeatureExtraction: boolean;
    /**
     * See {@link PartSettings.disableExpandElements}
     */
    disableExpandElements: boolean;
}

/**
 * A simple utility class for handling picking.
 *
 * This class performs picking in the view and returns the result in the callback specified with
 * {@link setPickResultCallback}. It also provides support for pick to hide parts, where hit parts are hidden
 * if the user holds down the Shift key while picking; and pick to set rotation point, where the rotation
 * point is set to the picked point if the user holds down the Ctrl key (Cmd on Mac) while picking.
 *
 * This class is meant for simple applications and would probably not meet the needs of more complex
 * apps. In such cases you would have to create your own picking handler.
 */
/** @deprecated **/
export class PickHelper {
    /**
     * Creates a pick handler and sets it as the pick handler for the given viewer.
     */
    constructor(viewer: Viewer);
    /**
     * Specifies the callback that will be invoked when the pick result is ready.
     *
     * See {@link RayIntersectCallback} for more information.
     */
    setPickResultCallback(pickResultCallback: ug.RayIntersectCallback): void;
}

/** @module cee.ug */ /** */
/**
 * Element interpolation type to use if the result is not PER_ELEMENT.
 */
export enum ElementInterpolationType {
    /**
     * Use the average value of all nodes.
     */
    AVERAGE = 0,
    /**
     * Use the minimum value of all nodes.
     */
    MIN = 1,
    /**
     * Use the maximum value of all nodes.
     */
    MAX = 2
}
export interface QueryAllElementResultsForFramePartData {
    /**
     * The zero-based geometryIndex of the part. A RemoteModel might have more than one geometry, but in most cases there is only one.
     * The combination of geometryIndex and partId uniquely identifies the part.
     */
    geometryIndex: number;
    /**
     * The id of the part. The id is >=0 and unique within the part's geometry.
     * The combination of geometryIndex and partId uniquely identifies the part.
     */
    partId: number;
    /**
     * The id of the cutting plane if the part is from a cutting plane.
     * This is -1 for element results for normal parts
     *
     * For cutting planes, a part will be produced for each part in each cutting plane
     * All elements that are intersected by the cutting plane will be included, and the centroid is the
     * centroid of the element projected onto the cutting plane.
     */
    cuttingPlaneId: number;
    /**
     * The element results for all elements in the part.
     *
     * Undefined values are set to NaN
     */
    elementScalarValues: Float32Array;
    /**
     * The element centroids for all elements in the part
     *
     * Coordinates are interleaved, so the array contains (x0, y0, z0, x1, y1, z1, ...)
     */
    elementCentroids: Float32Array;
    /**
     * The ID of the elements in the part (null if ids are not available)
     */
    elementIds: Int32Array | null;
    /**
     * The ID of the node contributing to the result if PER_NODE or PER_ELEMENT_NODE results and ids are available. Null if not.
     */
    nodeIds: Int32Array | null;
}
/**
 * The result of a {@link QueryAllElementResultsForFrame}
 */
export interface QueryAllElementResultsForFrameData {
    /**
     * Array with element info for each part.
     *
     * The array also contains info from cutting planes (per part) if there are any active cutting planes
     */
    partArr: QueryAllElementResultsForFramePartData[];
}
/**
 * Callback function invoked when the result of a {@link QueryAllElementResultsForFrame} is ready.
 */
export interface QueryAllElementResultsForFrameCallback {
    (data: QueryAllElementResultsForFrameData): void;
}
/**
 * Query to get element results and element centroids for all elements in a given frame
 *
 * For results mappings other than PER_ELEMENT, an interpolation type can be specified to determine
 * how to compute the element value (min, max or average of the element nodes).
 */
export class QueryAllElementResultsForFrame extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Gets element results and element centroids for all elements in the given frame
     *
     * @param frameIndex The zero-based frame index
     */
    executeQuery(frameIndex: number, callback: QueryAllElementResultsForFrameCallback): void;
    /**
     * Element interpolation type.
     *
     * If the result is not PER_ELEMENT, use this property to specify how to compute the per element result.
     * (Min/Max/Average).
     */
    get elementInterpolationType(): ElementInterpolationType;
    set elementInterpolationType(resultType: ElementInterpolationType);
}

/** @module cee.ug */ /** */
/**
 * The result of a {@link QueryBulkCalculation} for one part/region of cutting plane.
 */
export interface QueryBulkCalculationValues {
    /**
     * The index of the CAE geometry.
     *
     * In almost all cases this will be 0. If using a partially adaptive model with remeshing only on parts of the model (e.g. in a Forging process)
     * the concept of multiple geometries might be relevant.
     */
    geometryIndex: number;
    /**
     * The id of the part associated with the bulk values
     */
    partId: number;
    /**
     * Minimum per element surface scalar value in the region (either cutting plane or visible surface of the part)
     */
    minimumValue: number;
    /**
     * Maximum per element surface scalar value in the region (either cutting plane or visible surface of the part)
     */
    maximumValue: number;
    /**
     * Average per element surface scalar value in the region (either cutting plane or visible surface of the part)
     */
    averageValue: number;
    /**
     * Sum of SURFACE_AREA*SURFACE_RESULT_VALUE for all element surfaces in the region (of cutting planes) or
     * of the visible surface of a part.
     */
    resultant: number;
    /**
     * The position of the minimum per element surface scalar value {@link minimumValue} (surface centroid)
     */
    minimumValuePosition: Vec3;
    /**
     * The position of the maximum per element surface scalar value {@link maximumValue} (surface centroid)
     */
    maximumValuePosition: Vec3;
    /**
     * The minimum result for volume elements in the part (only applicable for parts with volume elements)
     */
    volumeMinimumValue: number;
    /**
     * The Maximum result for volume elements in the part (only applicable for parts with volume elements)
     */
    volumeMaximumValue: number;
    /**
     * The Average result for volume elements in the part (only applicable for parts with volume elements)
     */
    volumeAverageValue: number;
    /**
     * Sum of ELEMENT_VOLUME*ELEMENT_RESULT_VALUE for all volume elements (only applicable for parts with volume elements)
     */
    volumeResultant: number;
    /**
     * The position of the minimum result for volume elements in the part {@link volumeMinimumValue}
     */
    volumeMinimumValuePosition: Vec3;
    /**
     * The position of the maximum result for volume elements in the part {@link volumeMaximumValue}
     */
    volumeMaximumValuePosition: Vec3;
    /**
     * Minimum value of the nodes referenced by the region/part visible surface (applicable for PER_NODE and PER_ELEMENT_NODE results)
     */
    nodeMinimumValue: number;
    /**
     * Maximum value of the nodes referenced by the region/part visible surface (applicable for PER_NODE and PER_ELEMENT_NODE results)
     */
    nodeMaximumValue: number;
    /**
     * Average value of the nodes referenced by the region/part visible surface (applicable for PER_NODE and PER_ELEMENT_NODE results)
     */
    nodeAverageValue: number;
    /**
     * The position of the minimum value of the nodes referenced by the region/part visible surface {@link nodeMinimumValue}
     */
    nodeMinimumValuePosition: Vec3;
    /**
     * The position of the maximum value of the nodes referenced by the region/part visible surface {@link nodeMaximumValue}
     */
    nodeMaximumValuePosition: Vec3;
    /**
     * Minimum value of the nodes referenced by the volume elements in the part (applicable for PER_NODE and PER_ELEMENT_NODE results)
     */
    volumeNodeMinimumValue: number;
    /**
     * Maximum value of the nodes referenced by the volume elements in the part (applicable for PER_NODE and PER_ELEMENT_NODE results)
     */
    volumeNodeMaximumValue: number;
    /**
     * Average value of the nodes referenced by the volume elements in the part (applicable for PER_NODE and PER_ELEMENT_NODE results)
     */
    volumeNodeAverageValue: number;
    /**
     * The position of the minimum value of the nodes referenced by the volume elements in the part {@link volumeNodeMinimumValue}
     */
    volumeNodeMinimumValuePosition: Vec3;
    /**
      * The position of the maximum value of the nodes referenced by the volume elements in the part {@link volumeNodeMaximumValue}
      */
    volumeNodeMaximumValuePosition: Vec3;
    /**
     * The surface area of the region/part
     */
    area: number;
    /**
     * The volume of the part (only applicable for parts with volume elements). For cutting planes: the volume of the intersected elements
     */
    volume: number;
    /**
     * Number of element surfaces in the region/visible surface of the part
     */
    surfaceCount: number;
    /**
     * Number of nodes in the region / on the visible surface of the part
     */
    nodeCount: number;
    /**
     * Number of elements. For cutting planes: The number of elements intersected
     */
    elementCount: number;
    /**
     * The centroid of the region/part
     */
    centroid: Vec3;
    /**
     * The minimum corner of the bounding box of the part or the cutting plane region
     */
    boundingBoxMinimum: Vec3;
    /**
     * The maximum corner of the bounding box of the part or the cutting plane region
     */
    boundingBoxMaximum: Vec3;
    /**
     * A tessellation of triangles of the cutting plane region if a cutting plane query was issued and includeRegionTriangles was true
     *
     * This array contains x,y,z values for each triangle vertex. So there will be 9 values (3 vertices * (x,y,z)) per triangle.
     * This can be used to highlight the selected region using the geometry or the markup model.
     */
    regionTriangleVertices: Float32Array | null;
}
/**
 * Callback function invoked when the result of a {@link QueryBulkCalculation} is ready.
 *
 * In case of an error, the `data` argument in the callback will be null.
 */
export interface QueryBulkCalculationCallback {
    (err: Error | null, data: QueryBulkCalculationValues[]): void;
}
/**
 * Calculation of bulk values from cutting planes and visible surfaces of parts.
 *
 * The following values are computed on the cutting plane/part surface:
 *
 * - Scalar value: Min/Max/Average/Resultant(sum of Area*EltResult for all surface elements).
 * - Geometry:     Area, surface (triangle) count, node count, surface centroid.
 *
 * For scalar results, a per element result (maybe interpolated) is used for the calculations.
 *
 * For vector results, a dot product between the per element vector result (maybe interpolated) and the
 * surface normal is used to compute the scalar value for the element. This is then used to compute
 * min/max/avg/resultant. This will enable computation of flux/flow through the surface.
 *
 * Note that bulk calculations can be performed on any result, not only the ones currently
 * mapped on the model/cutting plane.
 *
 * For cutting planes, bulk values will be calculated per region, causing one cutting plane to
 * provide more than one region if it consists of two separate spacial regions.
 */
export class QueryBulkCalculation extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query for the given cutting plane.
     *
     * The query will return bulk values for each region of the cutting plane. The cutting plane will
     * be split into one region for each part, and also further split if the cutting plane for one part
     * consists of two or more spatially separate regions.
     *
     * Supported result types are: ResultType.SCALAR and ResultType.VECTOR
     */
    executeCuttingPlaneQuery(frameIndex: number, cuttingPlaneId: number, resultType: ResultType, resultId: number, callback: QueryBulkCalculationCallback): void;
    /**
     * Specify if the cutting plane queries should include triangle tessellation for each reg
     */
    get includeRegionTriangles(): boolean;
    set includeRegionTriangles(includeTriangles: boolean);
    /**
     * Executes the query for the given part.
     *
     * The bulk values are computed based on the elements referenced by the visible surfaces of the part.
     *
     * This query will provide one QueryBulkCalculationValues object with the bulk  values for this part.
     *
     * Supported result types are: ResultType.SCALAR and ResultType.VECTOR
     */
    executePartQuery(frameIndex: number, geometryIndex: number, partId: number, resultType: ResultType, resultId: number, callback: QueryBulkCalculationCallback): void;
}

/** @module cee.ug */ /** */
/**
 * Info about an element in a given frame
 */
export interface QueryElementInfoData {
    /**
     * The index of the frame
     */
    frameIndex: number;
    /**
     * The state id of the frame
     */
    stateId: number;
    /**
     * The index of the CAE geometry. In almost all cases this will be 0
     */
    geometryIndex: number;
    /**
     * The id of the part containing the element
     */
    partId: number;
    /**
     * The id of the element
     */
    elementId: number;
    /**
     * The index of the element
     */
    elementIndex: number;
    /**
     * The type of the element, for example 'Quad', 'Tetrahedron', 'Hexahedron'
     */
    elementType: string;
    /**
     * The volume of the element (if applicable)
     */
    elementVolume: number;
    /**
     * The area of the element (if applicable)
     */
    elementArea: number;
    /**
     * The centroid of the element.
     */
    elementCentroid: number[];
    /**
     * A tessellation of triangles of the element.
     *
     * This array contains x,y,z values for each triangle vertex. So there will be 9 values (3 vertices * (x,y,z)) per triangle.
     * This can be used to highlight the element using the geometry or the markup model.
     *
     */
    elementTriangleVertices: number[];
    /**
     * The scalar value of the element.
     */
    scalarResult: number | undefined;
    /**
     * The vector result(s) in the element. The array will contain 3 values (x,y,z) for each vector result.
     */
    vectorResultArr: number[];
    /**
     * Data for all element nodes
     */
    elementNodes: {
        /**
         * The index of the node.
         */
        nodeIndex: number;
        /**
         * The id of the node.
         */
        nodeId: number;
        /**
         * The position of the node.
         */
        position: number[];
        /**
         * The scalar value of the node.
         */
        scalarResult: number | undefined;
        /**
         * The vector result(s) in the element. The array will contain 3 values (x,y,z) for each vector result.
         */
        vectorResultArr: number[];
    }[];
}
/**
 * Callback function invoked when the result of a {@link QueryElementInfo} is ready. `elementInfoArr` will be null in case there is an error.
 */
export interface QueryElementInfoCallback {
    (error: Error | null, elementInfoArr: QueryElementInfoData[]): void;
}
/**
 * Query information about elements for a given frame or all frames
 *
 */
export class QueryElementInfo extends RemoteQuery {
    /**
     * Specify whether the `elementIdentArr` parameter in {@link executeQuery} is to be interpreted as an array of IDs or indices.
     * Defaults to IDs.
     */
    get elementIdentType(): RemoteQueryInputIdentType;
    set elementIdentType(identType: RemoteQueryInputIdentType);
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query for the given elements.
     *
     * @param frameIndex The index of the frame to get info for. Specify -1 for all frames
     * @param geometryIndex The index of the geometry the part belongs to. In most cases there is only
     * one geometry and this parameter should be 0. Specify -1 to search in all geometries.
     * @param partId The id of the part containing the elements. Specify -1 to search in all parts.
     * @param elementIdentArr Array with ids or indices of the elements to get information for. Use {@link elementIdentType} to specify what this array contains.
     * @param scalarResultId The id of the scalar to use for scalarResult. If -1 then the result currently shown as scalar fringes on the part will be used.
     * @param vectorResultId The id of the vector to use for vectorResults. If -1 then the vector results currently set in the modelSpec will be used.
     * @param callback Function getting called when the result is received from the server.
     */
    executeQuery(frameIndex: number, geometryIndex: number, partId: number, elementIdentArr: number[], scalarResultId: number, vectorResultId: number, callback: QueryElementInfoCallback): void;
    /**
     * Executes the query for the given ClientSideHitItem array.
     *
     * @param hitItems The client-side hit items to execute the query over. Use {@link RemoteModel.clientSideRayIntersect} or
     * {@link TrianglePicker} to create client-side hit items.
     * @param scalarResultId The id of the scalar to use for scalarResult. If -1 then the result currently shown as scalar fringes on the part will be used.
     * @param vectorResultId The id of the vector to use for vectorResults. If -1 then the vector results currently set in the modelSpec will be used.
     * @param callback Function getting called when the result is received from the server.
     */
    executeQueryByClientSideHitItems(hitItems: ClientSideHitItem[], scalarResultId: number, vectorResultId: number, callback: QueryElementInfoCallback): void;
}

/** @module cee.ug */ /** */
/**
 * Feature extraction type (cut, iso, isovolume)
 */
export enum FeatureExtractionType {
    /** Cutting plane */
    CUTTING_PLANE = 0,
    /** Isosurface */
    ISOSURFACE = 1,
    /** Isovolume */
    ISOVOLUME = 2
}
/**
 * Data for one surface (part) of a feature extraction (cut, iso, isovolume).
 */
export interface QueryFeatureExtractionSurface {
    /**
    * The index of the geometry the item belongs to.
    */
    geometryIndex: number;
    /**
     * The id of the part the item belongs to.
     */
    partId: number;
    /**
     * The triangulation of the feature extraction surface
     *
     * This array contains x,y,z values for each triangle vertex. So there will be 9 values (3 vertices * (x,y,z)) per triangle.
     */
    faceTriangleVertices: number[];
    /**
     * Edges (e.g. cutting plane intersecting with 2d elements)
     * This array contains x,y,z values for each edge. So there will be 6 values (2 vertices * (x,y,z)) per edge (from -> to).
     */
    edgeLineVertices?: number[];
    /**
     * Line segments representing the element mesh on the feature extraction surface.
     * There will be 6 values (2 vertices * (x,y,z)) per edge (from -> to).
     */
    elementMeshVertices?: number[];
    /**
     * Data per triangle of the feature extraction surface
     *
     * Source element index and results per triangle
     */
    triangleDataArr: {
        sourceElementIndex: number;
        scalarResult?: number;
        vectorResult?: number[];
        perVertexScalarResults?: number[];
        perVertexVectorResults?: number[];
    }[];
    /**
     * Data per edge of the feature extraction surface
     *
     * Source element index and results per edge
     */
    edgeDataArr: {
        sourceElementIndex: number;
        scalarResult?: number;
        vectorResult?: number[];
        perVertexScalarResults?: number[];
        perVertexVectorResults?: number[];
    }[];
}
/**
 * The result of a {@link QueryFeatureExtraction} query.
 */
export interface QueryFeatureExtractionData {
    /**
     *
     */
    featureExtractionType: FeatureExtractionType;
    /**
     * The zero-based frame index
     */
    frameIndex: number;
    /**
     * The zero-based geometryIndex of the part.
     */
    featureId: number;
    /**
     * Array of feature extraction surfaces (one per intersected part)
     */
    featureExtractionSurfaceArr: QueryFeatureExtractionSurface[];
}
/**
 * Callback function invoked when the result of a {@link QueryFeatureExtraction} is ready.
 */
export interface QueryFeatureExtractionCallback {
    (data: QueryFeatureExtractionData): void;
}
/**
 * Get the geometry and results of a feature extraction item (cutting plane, isosurface, isovolume)
 *
 * The query will return the tesselation (triangles and edges) of the requested item for the given
 * frame index. If a scalar result was mapped onto the surface, the query result will contain one
 * scalar value per triangle or edge vertex.
 *
 *
 */
export class QueryFeatureExtraction extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query to get information about the feature extraction item (cutting plane, isosurface, isovolume)
     */
    executeQuery(featureExtractionType: FeatureExtractionType, featureId: number, frameIndex: number, callback: QueryFeatureExtractionCallback): void;
    private createFeatureExtractionSurfaceArr;
}

/** @module cee.ug */ /** */
/**
 * Geometry statistics
 */
export interface QueryGeometryStatisticsData {
    /**
     * The total number of nodes
     */
    nodeCount: number;
    /**
     * The total number of element nodes
     */
    elementNodeCount: number;
    /**
     * The total number of elements
     */
    totalElementCount: number;
    /**
     * The number of null elements
     */
    nullElementCount: number;
    /**
     * The number of point elements
     */
    pointCount: number;
    /**
     * The number of beam elements
     */
    beamCount: number;
    /**
     * The number of beam3 elements
     */
    beam3Count: number;
    /**
     * The number of triangle elements
     */
    triangleCount: number;
    /**
     * The number of triangle6 elements
     */
    triangle6Count: number;
    /**
     * The number of quad elements
     */
    quadCount: number;
    /**
     * The number of quad8 elements
     */
    quad8Count: number;
    /**
     * The number of quad9 elements
     */
    quad9Count: number;
    /**
     * The number of tetrahedron elements
     */
    tetrahedronCount: number;
    /**
     * The number of tetrahedron10 elements
     */
    tetrahedron10Count: number;
    /**
     * The number of pyramid elements
     */
    pyramidCount: number;
    /**
     * The number of pyramid13 elements
     */
    pyramid13Count: number;
    /**
     * The number of pentahedron elements
     */
    pentahedronCount: number;
    /**
     * The number of pentahedron15 elements
     */
    pentahedron15Count: number;
    /**
     * The number of hexahedron elements
     */
    hexahedronCount: number;
    /**
     * The number of hexahedron20 elements
     */
    hexahedron20Count: number;
    /**
     * The number of polyhedron elements
     */
    polyhedronCount: number;
    /**
     * The number of brick elements
     */
    brickCount: number;
    /**
     * The number of shell elements
     */
    shellCount: number;
    /**
     * The number of thick shell elements
     */
    thickShellCount: number;
    /**
     * The number of rigid shell elements
     */
    rigidShellCount: number;
    /**
     * The number of unknown elements
     */
    unknownCount: number;
    /**
     * The total volume
     */
    totalVolume: number;
    /**
     * The total volume
     */
    totalArea: number;
}
/**
 * Callback function invoked when the result of a {@link QueryGeometryStatistics} is ready.
 */
export interface QueryGeometryStatisticsCallback {
    (statistics: QueryGeometryStatisticsData): void;
}
/**
 * Query geometry statistics such as element counts by type
 *
 */
export class QueryGeometryStatistics extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query for the given frame.
     *
     * @param frameIndex The index of the frame to get statistics for. Must be a valid index, wildcard is not supported.
     * @param geometryIndex The index of the geometry to get statistics for. Specify -1 for all geometries.
     * @param partId The id of the part to get statistics for. Specify -1 for all parts.
     * @param callback Function getting called when the result is received from the server.
     */
    executeQuery(frameIndex: number, geometryIndex: number, partId: number, callback: QueryGeometryStatisticsCallback): void;
}

/** @module cee.ug */ /** */
/**
 * The position of a node in the given frames.
 */
export interface QueryGlobalNodePositionsForFramesDataItem {
    /**
     * The ident of the node
     */
    nodeIdent: NodeIdent;
    /**
     * The Frame indices in the query
     */
    frameIndices: number[];
    /**
     * The global position of the node for each frame in {@link frameIndices}
     */
    globalNodePositions: Vec3[];
}
/**
 * The result of a {@link QueryGlobalNodePositionsForFrames} query
 */
export interface QueryGlobalNodePositionsForFramesData {
    /**
     * Node position data for each node in the query
     */
    nodePositionArr: QueryGlobalNodePositionsForFramesDataItem[];
}
/**
 * Callback function invoked when the result of a {@link QueryGlobalNodePositionsForFrames} is ready.
 */
export interface QueryGlobalNodePositionsForFramesCallback {
    (data: QueryGlobalNodePositionsForFramesData): void;
}
/**
 * Query to get the global position of a given node(s) in a given frame(s).
 */
export class QueryGlobalNodePositionsForFrames extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Gets the global position of the given node in the given frame(s).
     *
     * @param frameIndex The zero-based frame index, or -1 for all frames
     */
    executeQuery(frameIndex: number, nodes: NodeIdent[], callback: QueryGlobalNodePositionsForFramesCallback): void;
}

/** @module cee.ug */ /** */
/**
 * The result of a {@link QueryMapResultOnPoints} query
 */
export interface QueryMapResultOnPointsData {
    /**
     * Array with results per point. For scalar results there will be one value per point, for vector results there
     * will be three values per point.
     */
    pointResultArr: number[];
}
/**
 * Callback function invoked when the result of a {@link QueryMapResultOnPoints} is ready.
 */
export interface QueryMapScalarOnPointsCallback {
    (data: QueryMapResultOnPointsData): void;
}
/** Query the scalar or vector result in a given set of points.
 *
 * Use this query to compute the value of a given result in a set of points (coordinates) within the model.
 * The result will be loaded if needed, so you can specify any result available for the model.
 *
 * This class can be used to map results on the surface of a 3D solid.
 * See the example in Examples/DemoAppUg on how to do that.
 * Various 3D solid generators can be used to generate vertices and indices for this purpose, such as:
 * {@link cee.utils!CylinderGenerator utils.CylinderGenerator}, {@link cee.utils!BoxGenerator utils.BoxGenerator}
 * or {@link cee.utils!SphereGenerator utils.SphereGenerator}.
 */
export class QueryMapResultOnPoints extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Compute the value of the specified result in the given points (coordinates).
     *
     * @param frameIndex The zero based index of the frame to query the path from
     * @param resultId Id of the scalar result to map on the points
     * @param resultType Scalar and vector results are supported
     * @param pointArr 3D coordinates of the points interleaved (x0, y0, z0, x1, y1, z1, ...)
     */
    executeQuery(frameIndex: number, resultId: number, resultType: ResultType, pointArr: number[], callback: QueryMapScalarOnPointsCallback): void;
    /**
     * A non-negative tolerance value used when comparing point location with the model's elements.
     * Due to the way each point is checked to be inside the model or not, it is recommended to use a small tolerance value.
     * This is used to fine-tune the query to work well for querying points on (or very near) the surface of the model. @default 1e-6.
     */
    setTolerance(tolerance?: number): void;
}

/** @module cee.ug */ /** */
/**
 * Callback function invoked when the result of a {@link QueryNamedGeneric} is ready.
 *
 * The contents of data is dependent on the ID of the query.
 */
export interface QueryNamedGenericCallback {
    (data: any): void;
}
/** Custom query.
 *
 * Generic query provided as a framework for customized queries.
 */
export class QueryNamedGeneric extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Compute the custom query
     *
     */
    executeQuery(id: string, params: any, callback: QueryNamedGenericCallback): void;
}

/** @module cee.ug */ /** */
/**
 * The result of a {@link QueryNodeScalarResult}.
 */
export interface QueryNodeScalarResultData {
    /**
     * Id of the result on which the query was performed
     */
    resultId: number;
    /**
     * Ident of the node on which the query was performed
     */
    nodeIdent: NodeIdent;
    /**
     * The state reference values (usually time)
     */
    xValues: number[];
    /**
     * The scalar value in the node for each state in {@link xValues}
     */
    yValues: number[];
}
/**
 * Callback function invoked when the result of a {@link QueryNodeScalarResult} is ready.
 */
export interface QueryNodeScalarResultCallback {
    (data: QueryNodeScalarResultData): void;
}
/**
 * Query a scalar result for a given node across all states.
 *
 * Note that the states do not need to be "loaded", i.e. specified in the model spec.
 *
 * Only works with node-mapped results.
 */
export class QueryNodeScalarResult extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query for the given result and node.
     */
    executeQuery(resultId: number, nodeIdent: NodeIdent, callback: QueryNodeScalarResultCallback): void;
}

/** @module cee.ug */ /** */
/**
 * Info about a node in a given frame
 */
export interface QueryNodeInfoData {
    /**
     * The index of the frame
     */
    frameIndex: number;
    /**
     * The state id of the frame
     */
    stateId: number;
    /** The index of the CAE geometry. In almost all cases this will be 0 */
    geometryIndex: number;
    /** The id of the part containing the node */
    partId: number;
    /** The id of the node. */
    nodeId: number;
    /** The index of the node */
    nodeIndex: number;
    /** The coordinate of the node in the given frame */
    nodePosition: number[];
    /** The scalar value of the node. The result currently shown as scalar fringes on the part will be used. */
    scalarResult: number | undefined;
    /** Whether or not the {@link scalarResult} in this node is interpolated. */
    scalarResultIsInterpolated: boolean;
    /** The vector result(s) in the node. The array will contain 3 values (x,y,z) for each vector result specified in the model spec */
    vectorResultArr: number[];
    /** Id and index of all elements using the given node */
    elementsUsingNode: {
        elementIndex: number;
        elementId: number;
    }[];
}
/**
 * Callback function invoked when the result of a {@link QueryNodeInfo} is ready.
 */
export interface QueryNodeInfoCallback {
    (nodeInfoArr: QueryNodeInfoData[]): void;
}
/**
 * Query information about nodes for a given frame or all frames
 *
 */
export class QueryNodeInfo extends RemoteQuery {
    /**
     * Maximum number of nodes to be returned in the query.
     * Defaults to 1000.
     */
    get maxResultCount(): number;
    set maxResultCount(max: number);
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query for the given node ids
     *
     * @param frameIndex The index of the frame to get info for. Specify -1 for all frames
     * @param geometryIndex The index of the geometry the part belongs to. In most cases there is only
     * one geometry and this parameter should be 0. Specify -1 to search in all geometries for the node ids.
     * @param partId The id of the part containing the nodes. Specify -1 to search in all parts for the node ids.
     * @param nodeIdArr Array with ids of the nodes to get information for
     * @param callback Function getting called when the result is received from the server.
     */
    executeQueryByIds(frameIndex: number, geometryIndex: number, partId: number, nodeIdArr: number[], callback: QueryNodeInfoCallback): void;
    /**
     * Executes the query for the given region.
     *
     * The x and y coordinates must be specified in OpenGL style coordinates, which means a right handed coordinate system with the origin in the lower left corner of the window.
     * The HTML coordinate system is with origin in top left, so if this is your input (e.g. MouseEvent.offsetY, clientY, pageY, etc.) you will have to flip the Y coordinate.
     * The x and y are specified in native pixels, so you will have to adjust the input for the current devicePixelRatio (window.devicePixelRatio).
     *
     * The width and height are specified in native pixels. So you will have to adjust the input for the current devicePixelRatio (window.devicePixelRatio).
     *
     * @param frameIndex The index of the frame to get info for. Specify -1 for all frames.
     * @param geometryIndex The index of the geometry the part belongs to. In most cases there is only
     * one geometry and this parameter should be 0. Specify -1 to search in all geometries.
     * @param partId The id of the part containing the nodes. Specify -1 to search in all parts.
     * @param view The view which the given region applies to.
     * @param x The search region's x coordinate.
     * @param y The search region's y coordinate.
     * @param width The search region's width.
     * @param height The search region's height.
     * @param callback Function getting called when the result is received from the server.
     */
    executeQueryByRegion(frameIndex: number, geometryIndex: number, partId: number, view: View, x: number, y: number, width: number, height: number, callback: QueryNodeInfoCallback): void;
}

/** @module cee.ug */ /** */
/**
 * The result of a {@link QueryPartNodes}.
 */
export interface QueryPartNodesData {
    /**
     * The zero-based frame index
     */
    frameIndex: number;
    /**
     * The zero-based geometryIndex of the part.
     */
    geometryIndex: number;
    /**
     * The id of the part.
     */
    partId: number;
    /**
     * The global positions of all the nodes in the part
     */
    globalNodePositions: Vec3[];
}
/**
 * Callback function invoked when the result of a {@link QueryNodeScalarResult} is ready.
 */
export interface QueryPartNodesCallback {
    (data: QueryPartNodesData): void;
}
/**
 * Query all nodes of a given part in a given frame
 */
export class QueryPartNodes extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query to get the part nodes
     */
    executeQuery(frameIndex: number, geometryIndex: number, partId: number, callback: QueryPartNodesCallback): void;
}

/** @module cee.ug */ /** */
/**
 * The result data of a {@link QueryPartResults}.
 */
export interface QueryPartResultsData {
    /** The zero-based frame index.  */
    frameIndex: number;
    /** The zero-based geometryIndex of the part. */
    geometryIndex: number;
    /** The id of the part. */
    partId: number;
    /** Id of the result on which the query was performed. */
    resultId: number;
    /** Type of result. Scalar or vector type is supported. */
    resultType: ResultType;
    /**
     * The result mapping of the specified result. The mappings supported by this query are {@link ResultMapping.PER_NODE},
     * {@link ResultMapping.PER_ELEMENT} and {@link ResultMapping.PER_ELEMENT_NODE}.
     */
    resultMapping: ResultMapping;
    /**
     * Data per item. Depending on {@link resultMapping}, This will be per node for {@link ResultMapping.PER_NODE}, per element for {@link ResultMapping.PER_ELEMENT},
     * per element node for {@link ResultMapping.PER_ELEMENT_NODE}.
     */
    itemDataArr: QueryPartResultsDataItem[];
}
/**
 * The result data item of {@link QueryPartResultsData.itemDataArr}.
 */
export interface QueryPartResultsDataItem {
    /**
     * The id of the item. This is the node ID for {@link ResultMapping.PER_NODE} and {@link ResultMapping.PER_ELEMENT_NODE} mapping
     * and element ID for {@link ResultMapping.PER_ELEMENT} mapping.
     */
    itemId: number;
    /** The position of the item. Node position or the element centroid in case of {@link ResultMapping.PER_ELEMENT}. */
    itemPosition: Vec3;
    /** Per item result. One value for scalar results and a triplet (x,y,z) for vector results ({@link QueryPartResultsData.resultType}). */
    itemResult: number[];
}
/**
 * Callback function invoked when the result of a {@link QueryPartResults} is ready.
 *
 * In case there is an `error`, `data` will be null.
 */
export interface QueryPartResultsCallback {
    (error: Error | null, data: QueryPartResultsData): void;
}
/**
 * Get the results of a part.
 */
export class QueryPartResults extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query to get result information about the given part.
     * @param geometryIndex The zero-based geometryIndex of the part.
     * @param frameIndex The frame index for which to get the data.
     * @param partId The id of the part.
     * @param resultId Id of the result for which the query fetches the values.
     * @param resultType Type of the resultId ({@link ResultType.SCALAR} or {@link ResultType.VECTOR}).
     */
    executeQuery(frameIndex: number, geometryIndex: number, partId: number, resultId: number, resultType: ResultType, callback: QueryPartResultsCallback): void;
    private toQueryPartResultsDataItemArray;
}

/** @module cee.ug */ /** */
/**
 * Type of position for the query to return
 */
export enum SurfacePositionType {
    /**
     * The query will return the centroid of all visible element surfaces on the given part
     */
    ELEMENT_SURFACE_CENTROID = 0,
    /**
     * The query will return all nodes on the visible surface of the given part
     */
    NODE = 1,
    /**
     * The query will return all nodes that are on an outline edge of the visible surface og the given part.
     * This will typically be external/border nodes for a flat 2D surface (e.g. an inlet).
     */
    OUTLINE_NODE = 2,
    /**
     * The query will return all nodes that are not on an outline edge of the visible surface og the given part.
     * This will typically be internal nodes for a flat 2D surface (e.g. an inlet).
     */
    NON_OUTLINE_NODE = 3
}
/**
 * The result of a {@link QueryPartSurfacePositions}.
 */
export interface QueryPartSurfacePositionsData {
    /**
     * The zero-based frame index
     */
    frameIndex: number;
    /**
     * The zero-based geometryIndex of the part.
     */
    geometryIndex: number;
    /**
     * The id of the part.
     */
    partId: number;
    /**
     * The centroids of all the nodes in the query data. The array is interleaved (x0, y0, z0, x1, y1, ... zn)
     */
    positionArr: Float32Array;
    /**
     * The normals of all the nodes in the query data. The array is interleaved (x0, y0, z0, x1, y1, ... zn)
     */
    normalArr: Float32Array;
    /**
     * The id of the node/element for all the nodes in the query data
     */
    itemIdArr: Int32Array;
}
/**
 * Callback function invoked when the result of a {@link QueryPartSurfacePositions} is ready.
 */
export interface QueryPartSurfacePositionsCallback {
    (data: QueryPartSurfacePositionsData): void;
}
/**
 * Query information about positions on the visible surface of a part
 *
 * See {@link QueryPartSurfacePositionsData} for more information about the result of the query.
 *
 */
export class QueryPartSurfacePositions extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query to get information about the display part
     */
    executeQuery(positionType: SurfacePositionType, frameIndex: number, geometryIndex: number, partId: number, callback: QueryPartSurfacePositionsCallback): void;
}

/** @module cee.ug */ /** */
/**
 * A min or max item from {@link QueryResultMinMax}
 */
export interface QueryResultMinMaxDataItem {
    /** Minimum/maximum value. The array will have one item for scalars and 3 items (x,y,z) for vector and displacements */
    value: number[];
    /**
     * Position <x,y,z> of the minimum item. This will be the node for PER_NODE and PER_ELEMENT_NODE results,
     * element centroid for PER_ELEMENT results and element surface centroid for PER_SURFACE results.
     * */
    position: number[];
    /** The id of the state with the value */
    stateId: number;
    /** The id of the part with the value */
    partId: number;
    /** The id of the element with the value. -1 for PER_NODE results.*/
    elementId: number;
    /** The zero based index of the element with the value. -1 for PER_NODE results.*/
    elementIndex: number;
    /** The zero based index of the element node / element surface. -1 for PER_NODE and PER_ELEMENT results.*/
    elementSubIndex: number;
    /** The id of the node with the value. -1 for PER_ELEMENT and PER_SURFACE results. */
    nodeId: number;
    /** The zero based index of the node with the value. -1 for PER_ELEMENT and PER_SURFACE results. */
    nodeIndex: number;
}
/**
 * The result of a {@link QueryResultMinMax}.
 */
export interface QueryResultMinMaxData {
    /** Id of the result on which the query was performed */
    resultId: number;
    /** Ident of the node on which the query was performed */
    resultType: ResultType;
    /** The minimum item found */
    minimumItem: QueryResultMinMaxDataItem;
    /** The maximum item found */
    maximumItem: QueryResultMinMaxDataItem;
    /** The result mapping of the specified result. This will determine what kind of position the minimumItem and maximumItem are. */
    resultMapping: ResultMapping;
    /** Optional per state global min/max values. Note that these values are for all the data in the state and does not take filtering, visibility or a specific part into account.
     *
     * Set includeResultMinMaxForAllStates to true to enable per state global min/max data.
    */
    perStateGlobalMinMax?: {
        stateId: number;
        minimumValue: number;
        maximumValue: number;
    }[];
    /** Optional global minimum value. Note that this value is for all the data in the model and does not take filtering, visibility or a specific part into account.
     *
     * Set includeResultMinMaxForAllStates to true to enable per state global min/max data.
    */
    globalMinimumValue?: number;
    /** Optional global maximum value. Note that this value is for all the data in the model and does not take filtering, visibility or a specific part into account.
     *
     * Set includeResultMinMaxForAllStates to true to enable per state global min/max data.
    */
    globalMaximumValue?: number;
}
/**
 * Callback function invoked when the result of a {@link QueryResultMinMax} is ready.
 */
export interface QueryResultMinMaxCallback {
    (data: QueryResultMinMaxData): void;
}
/**
 * Query min/max items for a result based on the currently loaded states or a single state. Optionally
 * you can also query global min/max values for all states in the CAE model.
 *
 * You can query scalar, vector and displacement results, and the query supports all four result mappings:
 * Per node, per element, per element node and per element surface.
 *
 * The query for minimumItem and maximumItem applies default to the currently loaded states
 * (as specified in the ModelSpec.stateIdArray). It can however query results that are not currently
 * loaded on the server (not already mapped on the model). The results will be loaded if needed on the
 * server, but no new states will be loaded. If limitMinMaxItemsToFrameIndex is >= 0, the query will
 * compute the minimumItem and maximumItem only from the state at the specified frame index, and not
 * from the currently loaded states.
 *
 * The query for minimumItem and maximumItem can be limited to the currently visible parts by using the
 * executeQueryVisibleParts() method, or to a specific part by using the executeQueryForPart() method.
 *
 * In addition to queries for minimumItem and maximumItem, you can also get global min/max results
 * for all states (perStateGlobalMinMax, globalMinimumValue, globalMaximumValue). If
 * includeResultMinMaxForAllStates is set to true, you will in addition to whatever was specified for
 * the min/max items get global min/max for all states. Note these results are global and do not take
 * any filtering, visibility or specific part or frame index into consideration).
 *
 * The callback for {@link executeQuery}, {@link executeQueryVisibleParts} and {@link executeQuerySinglePart}
 * will return the data in an {@link QueryResultMinMaxData} object.
 */
export class QueryResultMinMax extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Executes the query for the given result
     *
     * The minimumItem/maximumItem will contain min/max for all the parts in the loaded state(s).
     *
     * Note: If includeResultMinMaxForAllStates is set to true, the data in QueryResultMinMaxData.perStateGlobalMinMax
     * and globalMinimumValue/globalMaximumValue will contain data for all states in the model, not only the loaded ones.
     */
    executeQuery(resultId: number, resultType: ResultType, callback: QueryResultMinMaxCallback): void;
    /**
     * Executes the query for for all visible items in the scene
     *
     * The minimumItem/maximumItem will contain min/max for the visible parts and element sets in the loaded state(s).
     *
     * Note: If includeResultMinMaxForAllStates is set to true, the data in QueryResultMinMaxData.perStateGlobalMinMax
     * and globalMinimumValue/globalMaximumValue will still be for the whole model.
     */
    executeQueryVisibleParts(resultId: number, resultType: ResultType, callback: QueryResultMinMaxCallback): void;
    /**
     * Executes the query for only one part
     *
     * The minimumItem/maximumItem will contain min/max for the specified part in the loaded state(s).
     *
     * Note: If includeResultMinMaxForAllStates is set to true, the data in QueryResultMinMaxData.perStateGlobalMinMax
     * and globalMinimumValue/globalMaximumValue will still be for the whole model.
     */
    executeQuerySinglePart(resultId: number, resultType: ResultType, geometryIndex: number, partId: number, callback: QueryResultMinMaxCallback): void;
    /**
     * Include global minimum and maximum values for all states.
     *
     * If set to true, the query will return an array with the per state global min/max for all states
     * in the database. For this the server will query the result file reader, and the min/max will be
     * the global min/max for each state, not taking any filtering (e.g. sets) into account.
     * The computeFromVisibleParts and query executeQueryForPart will also be ignored for the
     * global min/max and per state info.
     */
    get includeResultMinMaxForAllStates(): boolean;
    set includeResultMinMaxForAllStates(includeGlobalMinMaxForAllStates: boolean);
    /**
     * Optionally limit the returned QueryResultMinMaxDataItem.minimumItem and maximumItem to be computed
     * from only the state in the frame with the given frame index.
     *
     * If set to a value >= 0, the query will only consider the state with the given frame index when
     * computing the minimumItem and maximumItem.
     *
     * Default value is -1, which means that all frames will be queried.
     */
    get limitMinMaxItemsToFrameIndex(): number;
    set limitMinMaxItemsToFrameIndex(frameIndex: number);
}

/** @module cee.ug */ /** */
/**
 * An item in a set.
 */
export interface QuerySetItemsItem {
    /**
    * The index of the geometry the item belongs to.
    */
    geometryIndex: number;
    /**
     * The id of the part the item belongs to.
     */
    partId: number;
    /**
     * The index of the set item (element or node index depending on the Set item type)
     */
    itemIndex: number;
    /**
     * The sub-index of the set item. This is only applicable for Element_Edge, Element_Face and Element_Node sets and is the local face/edge/node index
     */
    subItemIndex: number;
}
/**
 * The result of a {@link QuerySetItems} query
 */
export interface QuerySetItemsData {
    /**
     * Array with set items
     */
    setItemArr: QuerySetItemsItem[];
    /**
     * If specified to be included in the query (QuerySetItems.getTesselationForFrameIndex >= 0) and
     * the set item type is ItemType.ELEMENT_FACE, this array will contain the tesselation of all the faces in the set.
     * For ItemType.ELEMENT it will contain all the faces of the element.
     *
     * This array contains x,y,z values for each triangle vertex. So there will be 9 values (3 vertices * (x,y,z)) per triangle.
     * This can be used to highlight the faces using the geometry or the markup model.
     */
    faceTriangleVertices?: number[];
    /**
     * If specified to be included in the query (QuerySetItems.getTesselationForFrameIndex >= 0) and
     * the set item type is ItemType.ELEMENT_EDGE, this array will contain the tesselation of all the edges in the set.
     *
     * This array contains x,y,z values for each edge. So there will be 6 values (2 vertices * (x,y,z)) per edge (from -> to).
     * This can be used to highlight the edges using the geometry or the markup model.
     */
    edgeLineVertices?: number[];
    /**
     * If specified to be included in the query (QuerySetItems.getTesselationForFrameIndex >= 0) and
     * the set item type is ItemType.ELEMENT_NODE or ItemType.NODE, this array will contain the tesselation of all the nodes in the set.
     *
     * This array contains x,y,z values for each node. So there will be 3 values (x,y,z) per node.
     * This can be used to highlight the edges using the geometry or the markup model.
     */
    nodeVertices?: number[];
}
/**
 * Callback function invoked when the result of a {@link QuerySetItems} is ready.
 */
export interface QuerySetItemsCallback {
    (data: QuerySetItemsData): void;
}
/**
 * Query to get all the items in a given set
 */
export class QuerySetItems extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Gets the global position of the given node in the given frame(s).
     *
     * @param setId Id of the set to query items from
     */
    executeQuery(setId: number, callback: QuerySetItemsCallback): void;
    /**
     * Specify if a tessellation of the specified set should be returned for a given frame index.
     *
     * Default is -1, which means no tesselation of the set will be provided.
     *
     * For ELEMENT_FACE sets, it will return a triangulation of the combined element faces in the set
     * in the QuerySetItemsItem.faceTriangleVertices array
     *
     * For ELEMENT_EDGE sets, it will return the lines of the combined element edges in the set
     * in the QuerySetItemsItem.edgeLineVertices array
     *
     * For ELEMENT_NODE sets, it will return the lines of the combined element edges in the set
     * in the QuerySetItemsItem.edgeLineVertices array
    */
    get getTesselationForFrameIndex(): number;
    set getTesselationForFrameIndex(includeTriangles: number);
}

/** @module cee.ug */ /** */
/**
 * The result of a {@link QuerySurfacePath} query
 */
export interface QuerySurfacePathData {
    points: {
        coordinate: Vec3Like;
        scalarResult: number;
    }[];
}
/**
 * Callback function invoked when the result of a {@link QuerySurfacePath} is ready.
 */
export interface QuerySurfacePathCallback {
    (data: QuerySurfacePathData): void;
}
/**
 * Enum specifying what kind of items that are in use
 */
export enum SurfacePathPointType {
    NODE = 0,
    ELEMENT = 1,
    COORDINATE = 2
}
/**
 * Defines one item on a surface path
 */
export interface SurfacePathItem {
    /**
     * Object type can be PART for part surfaces or CUTTING_PLANE, ISOSURFACE, or ISOVOLUME for extracted objects.
     */
    objectType: ObjectType;
    /**
     * The coordinate of the item (if SurfacePathPointType is COORDINATE)
     */
    coordinate: Vec3Like;
    /**
     * The index of the element (if SurfacePathPointType is ELEMENT)
     */
    elementIndex: number;
    /**
     * The index of the node (if SurfacePathPointType is NODE)
     */
    nodeIndex: number;
    /**
     * The index of the object (part, cutting plane, etc)
     */
    objectIndex: number;
}
/**
 * Query to get the path on the surface between the given points optionally with a sampled scalar result
 *
 * SurfacePathQuery will also produce a surface path for points on a cutting plane. All points
 * need to be one the same cutting plane.
 *
 * Mixing hits on parts AND cutting plane in the same query is not supported.
 *
 * This is useful for creating length plot of a scalar vs. length on the surface of the model.
 */
export class QuerySurfacePath extends RemoteQuery {
    /**
     *
     */
    constructor(model: RemoteModel);
    /**
     * Gets the surface path between the specified path items.
     *
     * @param frameIndex The zero based index of the frame to query the path from
     * @param pointType Type of points in the
     * @param surfacePathItemArr Array with SurfacePathItem describing the points defining the path
     */
    executeQuery(frameIndex: number, pointType: SurfacePathPointType, surfacePathItemArr: SurfacePathItem[], callback: QuerySurfacePathCallback): void;
    /**
     * Enable regular sampling along the path. Default off (0)
     */
    enableSampling(numSamples?: number): void;
}

/** @module cee.ug */ /** */
/**
 * Options for RemoteModel.openModel()
 *
 * @param defaultResultCalculatorDefinitions Provide setup of result calculators requiring an initString (e.g. expression) that
 * should be available when the model is opened. This will allow you to use this result in the OpenModelCallback passed
 * into openModel(). See {@link RemoteModel.createResultCalculator} for more info.
 *
 * Note: this is only needed for calculators that require an init string and not for calculators producing pre-defined results.
 *
 * @param configFlags Internal config flags used for debugging and testing of experimental features.
 *
 * Config flags:
 *
 * - maxcellchunk:   LOD setting for maximum of cells per chunk (spatially partitioned data) along longest extent of chunk bounding box. Default 80.
 * - maxcellglobal:  LOD setting for the total maximum of cells for all chunks along longest extent of model bounding box. Default 800.
 * - minecraft:      Only stream the LOD data. No full resolution data will be streamed. This is useful for testing LOD.
 * - singlestepmode: Only keep one state in memory on the server when setting up an animation. This will use less
 *   memory on the server, but will require reloading of data if anything is changed (moving cutting plane, changing result etc).
 *
 */
export interface OpenModelOptions {
    defaultResultCalculatorDefinitions?: ResultCalculatorDefinition[];
    configFlags?: string;
}
/**
 * A remote server CAE model that can be displayed in the client viewer.
 *
 * The RemoteModel is the controller of the visualization of the CAE model. Using this class you can
 * specify which results to show on the model, set part settings as well as create cutting
 * planes, isosurfaces, isovolumes and particle traces.
 *
 * Use {@link openModel} to open a CAE model residing on the server. Once the optional
 * callback passed to openModel is called, the {@link ModelDirectory} will have been populated and you can configure the
 * initial view of the model. If a callback is not provided to openModel then the first state is shown.
 *
 * **Example:** Minimal app, open default model on server:
 *
 *```javascript
 * var mySocket = io('http://localhost:8998');
 * var canvas = document.getElementById("myGlCanvas");
 *
 * mySession = new cee.CloudSession();
 *
 * myViewer = mySession.addViewer(canvas);
 * if (!myViewer) {
 *     return alert("No WebGL support");
 * }
 *
 * myModel = new cee.ug.RemoteModel(mySocket);
 * var myView = myViewer.addView();
 * myView.addModel(myModel);
 *
 * myModel.openModel("");
 *
 * function myAnimationFrameCallback(highResTimestamp) {
 *     mySession.handleAnimationFrameCallback(highResTimestamp);
 *     requestAnimationFrame(myAnimationFrameCallback);
 * }
 *
 * requestAnimationFrame(myAnimationFrameCallback);
 *```
 *
 * The {@link ModelSpec} is the object you use to specify what to show in the remote model. Here you
 * set which state(s) and results (scalar, vector, displacements) to display.
 * You can setup a state animation by setting {@link ModelSpec.stateIdArray}, or setup a mode shape animation with
 * {@link ModelSpec.modeShapeFrameCount} and {@link ModelSpec.modeShapeAnimationType}.
 * Animation is controlled by the Animation class which can be accessed with {@link animation}.
 *
 * You can access {@link PartSettings} objects with {@link getPartSettingsById}
 * and use them to set various part attributes such visibility, color, opacity and draw style.
 *
 * You can control how results are rendered with {@link ScalarSettings}, {@link VectorSettings} and
 * {@link DisplacementSettings} objects, which can be accessed with {@link getScalarSettingsById}, {@link getVectorSettingsById}
 * and {@link getDisplacementSettingsById} respectively.
 *
 * For volumetric models, you can add any number of cutting plane, isosurface, isovolume and particle
 * trace group objects to gain insight into the result distribution (e.g. flow field) within the model.
 * The settings of these items can be controlled with the {@link CuttingPlane}, {@link Isosurface},
 * {@link Isovolume}, and {@link ParticleTraceGroup} objects. Use {@link getCuttingPlaneById}, {@link getIsosurfaceById},
 * {@link getIsovolumeById} and {@link getParticleTraceGroupById} to access such objects.
 *
 * Picking is also done in the RemoteModel. Use {@link rayIntersect} to perform picking on the remote
 * server model. This method takes a callback which is called when the picking result is available.
 *
 * See the example in Examples/BuildYourFirstApp/3-FirstPostProcessor and 4-FeatureExtraction for how to use the RemoteModel
 *
 * **Example:** Show the last state with the first scalar result and modify part settings
 *
 *```javascript
 * // Get the model and the model directory from the RemoteModel
 * var modelDir = myModel.modelDirectory;
 *
 * // Show the last state in the analysis
 * var modelSpec = myModel.modelSpec;
 * modelSpec.stateIdArray =
 *       [modelDir.stateInfoArray[modelDir.stateInfoArray.length - 1].id];
 *
 *
 * // Show the first scalar as filled contours (if any)
 * if (modelDir.scalarResultArray.length > 0) {
 *     modelSpec.fringesResultId = modelDir.scalarResultArray[0].id;
 * }
 *
 * // Modify the part settings: First part transparent, the rest with element mesh
 * for (var i = 0; i < myModel.partCount; ++i) {
 *     var partSettings = myModel.getPartSettingsAt(i);
 *
 *     if (i == 0) {
 *         partSettings.drawStyle = cee.ug.DrawStyle.SURFACE;
 *         partSettings.opacity = 0.5;
 *     } else {
 *         partSettings.drawStyle = cee.ug.DrawStyle.SURFACE_MESH;
 *     }
 * }
 * ```
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/RemoteModel.png)
 */
export class RemoteModel extends Model implements ProcessableModel {
    /**
     * Creates a RemoteModel.
     *
     * A socket connection to a live UgServer must be provided.
     *
     * Example:
     * ```javascript
     * var mySocket = io('http://localhost:8998');
     * var myModel = new cee.ug.RemoteModel(mySocket, "");
     * ```
     */
    constructor(socketIOClient_socketInstance: any);
    /**
     * Static method to get custom server info from the UgServer.
     *
     * This info is specified on the server in the createServerInstance() method or the constructor to
     * ServerInstance.
     *
     * Default response is null.
     */
    static getCustomServerInfo(socketIOClient_socketInstance: any, callback: (customData: any) => void): void;
    /**
     * Name of the geometry model.
     *
     * Mainly used for debugging.
     */
    get name(): string;
    /**
     *
     *
     */
    set name(name: string);
    /**
     * The current {@link ModelDirectory}. This contains a table of contents of what is available
     * to display in the analysis on the server (time steps, results, etc).
     *
     * The {@link ModelDirectory} is fully available once the callback passed to {@link openModel} is called.
     * Until then, this is an empty `ModelDirectory` with no data.
     */
    get modelDirectory(): ModelDirectory;
    /** The model settings for this RemoteModel
     *
     * See {@link ModelSettings} for more info.
     */
    get modelSettings(): ModelSettings;
    /** The mirror/symmetry settings for this RemoteModel
     *
     * See {@link MirrorSettings} for more info.
     */
    get mirrorSettings(): MirrorSettings;
    /**
     * The animation control for this RemoteModel.
     */
    get animation(): Animation;
    /**
     * The specification of what to show in the remote model.
     *
     * The {@link ModelSpec} controls what is shown in the RemoteModel (states, results, mode-shape animation).
     *
     * The {@link modelSpec} is available once the callback passed to {@link openModel} is called.
     * Until then, this is an empty `ModelSpec` with no data and accessing its setters will throw an error.
     */
    get modelSpec(): ModelSpec;
    /**
     *The number of steps/frames in the viewer.
     *
     * The value of this property will be 1 if a model is loaded but contains no animation.
     * If an animation has been setup then the value will be the number of animation steps.
     */
    get frameCount(): number;
    /**
     * The step to show in the view.
     *
     * Use this property to specify a single step of the currently specified animation to show in the viewer.
     * The given zero-based index must be between 0 and {@link frameCount} - 1.
     *
     * Setting the current frame index will stop the animation if it is running.
     */
    get currentFrameIndex(): number;
    /**
     *
     *
     *
     *
     */
    set currentFrameIndex(frameIndex: number);
    /**
     * A description of the current step (e.g. time stamp, load case number, etc)
     */
    get currentStepText(): string;
    /**
     * The number of parts in the model.
     */
    get partCount(): number;
    /**
     * The number of scalar settings in the model.
     */
    get scalarSettingsCount(): number;
    /**
     * The number of vector settings in the model.
     */
    get vectorSettingsCount(): number;
    /**
     * The number of displacement settings in the model.
     */
    get displacementSettingsCount(): number;
    /**
     * The number of cutting planes in the model.
     */
    get cuttingPlaneCount(): number;
    /**
     * The number of isosurfaces in the model.
     */
    get isosurfaceCount(): number;
    /**
     * The number of isovolumes in the model.
     */
    get isovolumeCount(): number;
    /**
     * The number of particle trace groups in the model.
     */
    get particleTraceGroupCount(): number;
    /**
     * Set options for the reader with the given readerIdString
     *
     * The options will be sent to the server and used whenever a file of the given type is opened.
     *
     * Available options:
     *
     * - VTK (vtu/pvtu/pvd):
     *
     *   - readerIdString: "VTK"
     *   - options:
     *
     *     - ALL_VECTORS_AS_DISPLACEMENT (bool) : If set to true, all vector results in the file will be
     *       reported as displacements.
     *     - WELD_NODES_FOR_JOINT_PARTS (bool) : If set to true, all nodes in joint parts are welded together
     *     - WELD_NODES_PART_FIELD_NAME (string) : Set the name of the field used to identify parts in the model,
     *       for instance "PartID". The chosen field must contain integers. The default value is "".
     *       This option only applies when WELD_NODES_FOR_JOINT_PARTS is set to true.
     *
     * - HOOPS Access:
     *
     *   - readerIdString: "CEETRON_ACCESS" (most CAE formats)
     *   - options:
     *
     *     - USE_UNDEFINED_RESULTS (bool) : If true, undefined results will be reported as undefined. If false,
     *       undefined results will be reported as zero.
     *
     * OpenFoamProvider: See the readme file for the provider.
     *
     * Example:
     * ```
     * this.m_model.setReaderOptions("OpenFoamProvider", {
     *   "LOAD_BC_PARTS": true,
     *   "NODE_AVG_RES": true,
     *   "HIDE_PARALLEL_INTERFACES": false,
     *   "UPDATE_GEOMETRY_FOR_AMI": false
     * });
     * ```
     *
     * ```
     * this.m_model.setReaderOptions("VTK", {
     *     "ALL_VECTORS_AS_DISPLACEMENT": true,
     * });
     * ```
     */
    setReaderOptions(readerIdString: string, options: {
        [optionName: string]: string | number | boolean;
    }): void;
    /**
     * Set an array of key,value pairs that will be included as a context in the server log.
     *
     * This key,value pairs will be available in the JSON type log, and will be included until a
     * new key,value array is specified. To clear any current settings, pass in an empty array.
     *
     * This could be used to enhance the telemetry support in your cloud solution.
     */
    setServerLogContextKeyValueArr(keyValueArr: {
        key: string;
        value: string;
    }[]): void;
    /**
     * Opens the model with the given modelKey in this RemoteModel.
     *
     * Opens a model on the server and prepares to stream it to the client. If the model is opened successfully
     * (as indicated when the optional callback is invoked) the initial step of the CAE model will be
     * streamed to the client.
     *
     * @param modelKey The identifier of the model to open. This will be translated on the server into a
     * filename before the model is opened. This translation is done by the modelFileFromKey() function
     * that is provided to createServerInstance() on the visualization server.
     *
     * @param openCompletedCallback Callback function that will be called when the model is ready to be used
     * in the client. This will also be called if any errors occur (file not found etc.).
     * When this is called the ModelDirectory will have been populated with the contents of the server CAE analysis.
     *
     * @param options Open model options. Provide any default calculators and/or an internal configString. See OpenModelOptions
     * for more info.
     *
     * **Example:** Customize the initial appearance of the model in the callback:
     *
     * ```javascript
     * // Remove any old models
     * var view = myViewer.getViewAt(0);
     * view.removeAllModels();
     *
     * // Open a new RemoteModel from the CAE server
     * var mySocket = io('http://localhost:8998');
     * myModel = new cee.ug.RemoteModel(mySocket, "");
     * view.addModel(myModel);
     *
     * // Open the file on the server, setup the viz when it is done
     * myModel.openModel("", function(err, model) {
     *     // Note: The model is now ready to use and the ModelDirectory is populated
     *     // with the model context received from the server
     *
     *     // Show the first scalar as filled contours (if any)
     *     if (model.modelDirectory.scalarResultArray.length > 0) {
     *         model.modelSpec.fringesResultId = model.modelDirectory.scalarResultArray[0].id;
     *     }
     *
     *     // Modify the part settings: First part transparent, the rest with surf mesh
     *     for (var ps of model.getPartSettingsArray()) {
     *         ps.drawStyle = cee.ug.DrawStyle.SURFACE_OUTLINE_MESH;
     *         ps.opacity = 0.5;
     *     }
     * });
     * ```
     *
     * This code sample produces the following image in the 3D Viewer:
     *
     * ![](/images/RemoteModel_open.png)
     */
    openModel(modelKey: string, openCompletedCallback?: OpenModelCallback, options?: OpenModelOptions): void;
    /**
     * Closes the model, cleaning up on both the server and the client.
     */
    closeModel(): void;
    /**
     * Reload model, pick up any changes on the server since the open of the analysis.
     */
    reloadModel(reloadCompletedCallback?: ReloadModelCallback): void;
    /**
     * Apply the VTFx case with the given id to the model.
     *
     * The list of available VTFx cases with name and id can be found in ModelDirectory.vtfxCaseInfoArray
     */
    applyVTFxCase(caseId: number, applyVTFxCaseCompletedCallback?: ApplyVTFxCaseCallback): void;
    /**
     * Poll the current data source for changes.
     *
     * Note: Only one poll can be in flight at any given time, so calling this method while a poll is
     * being processed will throw. To make sure you do not do that, use the isPollForDataSourceChangesInProgress
     * method to check for any ongoing polls.
     */
    pollForDataSourceChanges(pollForDataSourceChangesCompletedCallback?: PollForDataSourceChangesCallback): void;
    /**
     * Returns true if a pollForDataSourceChanges call is in progress.
     *
     * Use this to check before calling pollForDataSourceChanges, as this will throw if a request is
     * in flight
     */
    isPollForDataSourceChangesInProgress(): boolean;
    /**
     * Send a request to the server data source (Data Provider).
     *
     * Note: Only one request can be in flight at any given time, so calling this method while a request is
     * being processed will throw. To make sure you do not do that, use the isDataSourceRequestInProgress()
     * method to check for any ongoing requests.
     */
    executeDataSourceRequest(message: string, data: string, callback?: DataSourceRequestCallback): void;
    /**
     * Returns true if an executeDataSourceRequest call is in progress.
     *
     * Use this to check before calling executeDataSourceRequest, as this will throw if a request is
     * in flight
     */
    isDataSourceRequestInProgress(): boolean;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the current contents of the RemoteModel
     *
     * Note that currently this method does not support {@link ModelBoundingBoxOptions} so the returned
     * bounding box will always be the "current" bounding box that accounts for visibility of parts/objects.
    */
    getBoundingBox(_options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the given part in the current frame.
     *
     * The bounding box returned is the bounding box of the specified part in the current frame, provided
     * that the part is visible and present on the client.
     */
    getClientSidePartBoundingBox(geometryIndex: number, partId: number): BoundingBox;
    /**
     * Returns default camera configuration for this model if it exists
     */
    getDefaultCameraConfig(): CameraConfig | null;
    /**
     * Set the title of the color legend with the given result Id
     *
     * This will update any current legends, and also be used as the title whenever the legend is later
     * created.
     */
    setColorLegendTitle(resultId: number, title: string): void;
    /**
     * Start the streaming of the initial 3d model from the server.
     *
     * Note: Calling this method is only needed when using the openCompletedCallback parameter to OpenModel and
     * returning POSTPONE_STREAMING.
     */
    startPostponedStreaming(): void;
    /**
     * Sets a handler function that will be called whenever an error packet is received from the
     * visualization server.
     */
    setServerErrorHandler(errorHandler: ServerErrorHandler): void;
    /**
     * Sets a handler function that will be called whenever a progress indication packet is received from the
     * visualization server.
     */
    setProgressHandler(progressHandler: ProgressHandler): void;
    /**
     * Sets a handler function that will be called with information about the current communication.
     *
     * See CommunicationPerformanceData for more information.
     */
    setCommunicationPerformanceHandler(performanceHandler: CommunicationPerformanceHandler): void;
    /**
     * Specifies the handler function that will be called whenever any result changes in the model.
     * This will be called when a result is loaded the first time or when changing time step.
     *
     * This might be useful for updating the UI, e.g. the minimum and maximum values on a slider for an isosurface.
     */
    setResultRangeChangedHandler(resultRangeChangedHandler: ResultRangeChangedHandler | null): void;
    /**
     * Returns the minimum value for all items currently loaded in the RemoteModel for the given
     * scalar result.
     *
     * The resultId must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     *
     * Note: This method only works for results that are currently in use in the client. If you need
     * the minimum value of any scalar result, you can use the {@link QueryResultMinMax} class.
     *
     * @returns Returns undefined if the result has not been loaded or if the resultId is invalid.
     */
    getScalarResultMinimumValue(resultId: number): number | undefined;
    /**
     * Returns the maximum value for all items currently loaded in the RemoteModel for the given
     * scalar result.
     *
     * The resultId must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     *
     * Note: This method only works for results that are currently in use in the client. If you need
     * the maximum value of any scalar result, you can use the {@link QueryResultMinMax} class.
     *
     * @returns Returns undefined if the result has not been loaded or if the resultId is invalid.
     */
    getScalarResultMaximumValue(resultId: number): number | undefined;
    /**
     * Returns the minimum length for all items currently loaded in the RemoteModel for the given
     * vector result.
     *
     * The resultId must refer to one of the vector results in {@link ModelDirectory.vectorResultArray}.
     *
     * @returns Returns undefined if the result has not been loaded or if the resultId is invalid.
     */
    getVectorResultMinimumLength(resultId: number): number | undefined;
    /**
     * Returns the maximum length for all items currently loaded in the RemoteModel for the given
     * vector result.
     *
     * The resultId must refer to one of the vector results in {@link ModelDirectory.vectorResultArray}.
     *
     * @returns Returns undefined if the result has not been loaded or if the resultId is invalid.
     */
    getVectorResultMaximumLength(resultId: number): number | undefined;
    /**
     * Returns the minimum length for all items currently loaded in the RemoteModel for the given
     * displacement result.
     *
     * The resultId must refer to one of the displacement results in {@link ModelDirectory.displacementResultArray}.
     *
     * @returns Returns undefined if the result has not been loaded or if the resultId is invalid.
     */
    getDisplacementResultMinimumLength(resultId: number): number | undefined;
    /**
     * Returns the maximum length for all items currently loaded in the RemoteModel for the given
     * displacement result.
     *
     * The resultId must refer to one of the displacement results in {@link ModelDirectory.displacementResultArray}.
     *
     * @returns Returns undefined if the result has not been loaded or if the resultId is invalid.
     */
    getDisplacementResultMaximumLength(resultId: number): number | undefined;
    /**
     * Returns the total number of elements in the given frame
     *
     * frameIndex must be <0..frameCount-1>
     *
     * @returns Returns undefined if data for the frame has not yet been received.
     */
    getElementCount(frameIndex: number): number | undefined;
    /**
     * Returns the total number of nodes in the given frame
     *
     * index must be <0..frameCount-1>
     *
     * @returns Returns undefined if data for the frame has not yet been received.
     */
    getNodeCount(frameIndex: number): number | undefined;
    /**
     * Enables pre-loading of data.
     *
     * If enabled, the server will stream all data specified in {@link ModelSpec.stateIdArray} to
     * prepare the client for an animation or for stepping through the states.
     *
     * If not enabled (default), data will only be streamed when needed (i.e. when a step is going to be displayed).
     */
    enablePreloading(enable: boolean): void;
    /**
     * Returns true if pre-loading is enabled.
     */
    isPreloadingEnabled(): boolean;
    /**
     * Adds a one-shot callback that will be called once the next server visualization update is complete.
     *
     * Whenever you change something in a RemoteModel, the pending changes will immediately be registered
     * client-side, but will not be dispatched to the remote server until later. This server update typically
     * happens in response to requestAnimationFrame() processing. The callback registered by this function will
     * only be triggered once the next server update has been dispatched and has completed.
     *
     * Please note that the callback will only be called once.
     */
    addNextServerUpdateCompletedCallback(serverVisuaizationUpdateCompleteCallback: ServerUpdateCompletedCallback): void;
    /**
     * Sets a one- shot callback that will be called the next time we observe that data streaming is complete
     */
    setOneShotDataStreamingCompleteCallback(dataStreamingCompleteCallback: DataStreamingCompleteCallback): void;
    /**
     * Performs picking on the remote server model.
     *
     * This will perform a picking action on the remote server with the given ray. The provided callback
     * will be called when the result is available. The hitItem provided to this callback will
     * contain detailed information about the element that was hit in the CAE model.
     *
     * To do the picking at the current state/time step, use the model.currentFrameIndex property.
     */
    rayIntersect(frameIndex: number, ray: Ray, rayIntersectCallback: RayIntersectCallback): void;
    /**
     * Returns {@link PartSettings} for all parts in the model.
     */
    getPartSettingsArray(): ReadonlyArray<PartSettings>;
    /**
     * Returns the part settings for the part with the given geometry index and part id.
     *
     * @param geometryIndex The index of the geometry the part belongs to. In most cases there is only
     * one geometry and this parameter should be 0.
     *
     * @param partId The id of the part to find.
     */
    getPartSettingsById(geometryIndex: number, partId: number): PartSettings | null;
    /**
     * Returns part settings for the part at the given index.
     *
     * The index must be between 0 and partCount - 1.
     */
    getPartSettingsAt(partIndex: number): PartSettings;
    /**
     * Sets the draw style for all parts in the model
     *
     * This is just a helper for setting {@link PartSettings.drawStyle} for all parts in the model, and optionally
     * set opacity if provided.
     */
    setDrawStyleAllParts(drawStyle: DrawStyle, opacity?: number): void;
    /**
     * Returns {@link ScalarSettings} for all scalar results in the model.
     */
    getScalarSettingsArray(): ReadonlyArray<ScalarSettings>;
    /**
     * Returns the {@link ScalarSettings} for the result at the given index.
     *
     * The index must be between 0 and scalarSettingsCount - 1.
     *
     * Use the returned object to modify the settings of the scalar result
     */
    getScalarSettingsAt(resultIndex: number): ScalarSettings;
    /**
     * Returns the {@link ScalarSettings} for the result with the given result id, or null if no match is found.
     *
     * The resultId must refer to one of the scalar results in {@link ModelDirectory.scalarResultArray}.
     *
     * Use the returned object to modify the settings of the scalar result
     */
    getScalarSettingsById(resultId: number): ScalarSettings | null;
    /**
     * Returns {@link VectorSettings} for all vector results in the model.
     */
    getVectorSettingsArray(): ReadonlyArray<VectorSettings>;
    /**
     * Returns the {@link VectorSettings} for the result at the given index.
     *
     * The index must be between 0 and vectorSettingsCount - 1.
     *
     * Use the returned object to modify the settings of the vector result
     */
    getVectorSettingsAt(resultIndex: number): VectorSettings;
    /**
     * Returns the {@link VectorSettings} for the result with the given result id, or null if no match is found.
     *
     * The resultId must refer to one of the vector results in {@link ModelDirectory.vectorResultArray}.
     *
     * Use the returned object to modify the settings of the vector result
     */
    getVectorSettingsById(resultId: number): VectorSettings | null;
    /**
     * Returns {@link DisplacementSettings} for all displacement results in the model.
     */
    getDisplacementSettingsArray(): ReadonlyArray<DisplacementSettings>;
    /**
     * Returns the {@link DisplacementSettings} for the result at the given index.
     *
     * The index must be between 0 and displacementSettingsCount - 1.
     *
     * Use the returned object to modify the settings of the displacement result.
     */
    getDisplacementSettingsAt(resultIndex: number): DisplacementSettings;
    /**
     * Returns the {@link DisplacementSettings} for the result with the given result id, or null if no match is found.
     *
     * The resultId must refer to one of the displacement results in {@link ModelDirectory.displacementResultArray}.
     *
     * Use the returned object to modify the settings of the displacement result.
     */
    getDisplacementSettingsById(resultId: number): DisplacementSettings | null;
    /**
     * Adds a {@link CuttingPlane} to the remote model.
     *
     * This will add a new cutting plane to the model. The cutting plane will be assigned an id by the
     * model.
     *
     * Note: Maximum number of clipping planes is 20
     *
     * @returns Returns the new {@link CuttingPlane}.
     */
    addCuttingPlane(): CuttingPlane;
    /**
     * Returns all {@link CuttingPlane}s in the model.
     */
    getCuttingPlaneArray(): ReadonlyArray<CuttingPlane>;
    /**
     * Returns the {@link CuttingPlane} at the given index.
     *
     * The index must be between 0 and cuttingPlaneCount - 1.
     *
     * Use the returned object to modify the settings of the cutting plane.
     */
    getCuttingPlaneAt(index: number): CuttingPlane;
    /**
     * Returns the {@link CuttingPlane} with the given id, or null if no match is found.
     *
     * Use the returned object to modify the settings of the cutting plane.
     */
    getCuttingPlaneById(id: number): CuttingPlane | null;
    /**
     * Deletes the {@link CuttingPlane} with the given id from the model.
     */
    deleteCuttingPlaneById(id: number): void;
    /**
     * Deletes all {@link CuttingPlane CuttingPlanes} from the model.
     */
    deleteAllCuttingPlanes(): void;
    /**
     * Adds an {@link Isosurface} to the remote model.
     *
     * This will add a new isosurface to the model. The isosurface will be assigned an id by the
     * model. Returns null if the adding fails.
     *
     * The default settings are:
     *
     * * {@link Isosurface.isoScalarResultId}: the fringes result or the first available scalar
     * * {@link Isosurface.mapScalarResultId}: same as above
     * * {@link Isosurface.isoValue}: the middle of the range if known, else 0.5
     *
     * @returns Returns the new {@link Isosurface}.
     */
    addIsosurface(): Isosurface | null;
    /**
     * Returns all {@link Isosurface Isosurfaces} in the model.
     */
    getIsosurfaceArray(): ReadonlyArray<Isosurface>;
    /**
     * Returns the {@link Isosurface} at the given index.
     *
     * The index must be between 0 and isosurfaceCount - 1.
     */
    getIsosurfaceAt(index: number): Isosurface;
    /**
     * Returns the {@link Isosurface} with the given id, or null if no match is found.
     */
    getIsosurfaceById(id: number): Isosurface | null;
    /**
     * Deletes the {@link Isosurface} with the given id from the model.
     */
    deleteIsosurfaceById(id: number): void;
    /**
     * Deletes all {@link Isosurface Isosurfaces} from the model.
     */
    deleteAllIsosurfaces(): void;
    /**
     * Adds an {@link Isovolume} to the remote model.
     *
     * This will add a new isovolume to the model. The isovolume will be assigned an id by the
     * model. Returns null if the adding fails.
     *
     * The default settings are:
     *
     * * {@link Isovolume.isoScalarResultId}: the fringes result or the first available scalar
     * * {@link Isovolume.mapScalarResultId}: same as above
     * * {@link Isovolume.minimumIsoValue}: the minimum of the range if known, else 0
     * * {@link Isovolume.maximumIsoValue}: the middle of the range if known, else 0.5
     *
     * @returns Returns the new {@link Isovolume}.
     */
    addIsovolume(): Isovolume | null;
    /**
     * Returns all the {@link Isovolume Isovolumes} in the model.
     */
    getIsovolumeArray(): ReadonlyArray<Isovolume>;
    /**
     * Returns the {@link Isovolume} at the given index.
     *
     * The index must be between 0 and isovolumeCount - 1.
     */
    getIsovolumeAt(index: number): Isovolume;
    /**
     * Returns the {@link Isovolume} with the given id, or null if no match is found.
     */
    getIsovolumeById(id: number): Isovolume | null;
    /**
     * Deletes the {@link Isovolume} with the given id from the model.
     */
    deleteIsovolumeById(id: number): void;
    /**
     * Delete all {@link Isovolume Isovolumes} from the model.
     */
    deleteAllIsovolumes(): void;
    /**
     * Adds a {@link ParticleTraceGroup} to the remote model.
     *
     * This will add a new particle trace group to the model. The group will be assigned an id by the
     * model.
     *
     * @returns Returns the new {@link ParticleTraceGroup}.
     */
    addParticleTraceGroup(): ParticleTraceGroup;
    /**
     * Returns all {@link ParticleTraceGroup ParticleTraceGroups} in the model.
     */
    getParticleTraceGroupArray(): ReadonlyArray<ParticleTraceGroup>;
    /**
     * Returns the {@link ParticleTraceGroup} at the given index.
     *
     * The index must be between 0 and particleTraceGroupCount - 1.
     */
    getParticleTraceGroupAt(index: number): ParticleTraceGroup;
    /**
     * Returns the {@link ParticleTraceGroup} with the given id, or null if no match was found.
     */
    getParticleTraceGroupById(id: number): ParticleTraceGroup | null;
    /**
     * Deletes the {@link ParticleTraceGroup} with the given id from the model.
     */
    deleteParticleTraceGroupById(id: number): void;
    /**
     * Deletes all {@link ParticleTraceGroup} from the model.
     */
    deleteAllParticleTraceGroups(): void;
    /**
     * Sets result calculator parameters for the given result calculator result.
     *
     * The result will automatically be updated.
     *
     * Example:
     * ```javascript
     * model.setResultCalculatorParams(calcId, resIdString,  { "scaleFactor" : 2.0 });
     * ```
     */
    setResultCalculatorParams(calculatorId: string, resultIdString: string, paramsDict: {
        [paramName: string]: number;
    }): void;
    /**
     * Create a new result calculator result based on the given specification.
     *
     * Result calculators are created with the Result Calculator Framework and loaded as .dll/.so/.dylib
     * on the server. A calculator can be initialized with an initString. This string contains the configuration
     * of the calculator (e.g. a mathematical expression).
     *
     * @param config See {@link CreateResultCalculatorConfig}
     * @param callback An optional callback function triggered when the new result is available.
     *               From this method you can locate the newly created result in the model directory
     *               (using the calculatorId and resultIdString) and then e.g. apply it to the model.
     *
     * @example
     * ```javascript
     * // Basic usage
     * model.createResultCalculator({
     *     calculatorId: "MyCalculator",
     *     resultIdString: "MyResult",
     *     initString: "MyCustomExpression"
     * });
     *
     * // With coordinate system
     * model.createResultCalculator({
     *     calculatorId: "MyCalculator",
     *     resultIdString: "MyResult",
     *     initString: "MyCustomExpression",
     *     coordSystemString: "type=cylindrical;origin=10.0,5.0,0.0;orientation=1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0"
     * });
     * ```
     */
    createResultCalculator(config: CreateResultCalculatorConfig, callback?: CreateResultCalculatorCallback): void;
    /**
     * Recreate the result with the given calculatorId and resultIdString.
     *
     * Use this method to update an already existing calculator result. From the client side it will seem like the result is just
     * updated with the new initString, but on the server the actual calculator instance will be deleted and a new one
     * will be initialized with the given initString.
     *
     * The result will keep its id (number) so no updates are needed to the model spec or feature extraction items.
     *
     * @param config See {@link CreateResultCalculatorConfig}
     * @param callback An optional callback function triggered when the new result is available
     *
     * @example
     * ```javascript
     * // Basic usage
     * model.recreateResultCalculator({
     *     calculatorId: "MyCalculator",
     *     resultIdString: "MyResult",
     *     initString: "MyCustomExpression"
     * });
     *
     * // With coordinate system
     * model.recreateResultCalculator({
     *     calculatorId: "MyCalculator",
     *     resultIdString: "MyResult",
     *     initString: "MyCustomExpression",
     *     coordSystemString: "type=cylindrical;origin=10.0,5.0,0.0;orientation=1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0"
     * });
     * ```
     */
    recreateResultCalculator(config: CreateResultCalculatorConfig, callback?: CreateResultCalculatorCallback): void;
    /**
     * Delete the result calculator with the given calculator id and result idString
     */
    deleteResultCalculator(calculatorId: string, resultIdString: string): void;
    /**
     * Share the model on the web using the Envision One-Click-Sharing service.
     *
     * With this method you can share the remote model (with the current settings) to the Ceetron Cloud
     * cloud service.
     *
     * You can either use the default https://cloud.ceetron.com service, or use your own hosted sharing portal.
     * The Ceetron Cloud Portal can be customized and installed on most cloud and on-premises servers.
     */
    sendToCloud(view: View, config: SendToCloudConfig, callback: SendToCloudCallback): void;
    /**
     * Performs a client-side (not on server) ray pick.
     *
     * This might be faster or slower than a server pick request, depending on model size, latency,
     * server capabilities and client capabilities. Note that this picking only considers visible
     * surface geometry.
     *
     * If something was hit, returns a ClientSideHitItem object containing information about the hit.
     * Returns null if nothing was hit
     */
    clientSideRayIntersect(ray: Ray): ClientSideHitItem | null;
    /**
     * Creates a VisibleObjectPicker for this model and the specified view.
     *
     * Returns null if no picker can be created, typically because WebGL resources have been exhausted.
     *
     * This support class is used to get information about the visible items in the model.
     * Given a rectangular region, this class can return the parts/objects that are currently visible in that region.
     *
     * See {@link VisibleObjectPicker} for more information.
     */
    createVisibleObjectPicker(view: View): VisibleObjectPicker | null;
    /**
     * Creates a TrianglePicker for this model and the specified view.
     *
     * Returns null if no picker can be created, typically because WebGL resources have been exhausted.
     *
     * See {@link TrianglePicker} for more information.
     */
    createTrianglePicker(view: View): TrianglePicker | null;
    /**
     * Determines whether the given point is currently covered by a surface in the given view.
     */
    isPointCoveredBySurface(point: Vec3, view: View): boolean;
    /**
     * Returs true when the model is successfully opened, i.e. once the callback passed to {@link openModel} is called.
     */
    isOpen(): boolean;
}

/** @module cee.ug */ /** */
export interface OpenModelInfo {
    serverCameraConfig?: CameraConfig;
}
/**
 * Return actions from OpenModelCallback.
 *
 * START_STREAMING or void: Immediately start streaming
 * POSTPONE_STREAMING: Postpone streaming, do not start until RemoteModel.startPostponedStreaming() is called.
 */
export enum OpenModelCallbackCompletedAction {
    START_STREAMING = 0,
    POSTPONE_STREAMING = 1
}
/**
 * Callback that is invoked when the opening of a model is complete. If there were no errors, the {@link ModelDirectory} will have
 * been populated once this is called.
 *
 * If you need to do any async calls or want to do something else before the streaming starts, return POSTPONE_STREAMING from
 * this callback. When you are done and would like the model to start the initial streaming, call the startPostponedStreaming() function.
 *
 * If you return nothing or START_STREAMING the streaming of the model will start immediately.
 *
 * Note: DO NOT do any async calls in the callback unless you return POSTPONE_STREAMING!
 */
export interface OpenModelCallback {
    (error: Error | null, model: RemoteModel, info: OpenModelInfo | null): OpenModelCallbackCompletedAction | void;
}
export interface ReloadModelCallback {
    (error: Error | null, model: RemoteModel): void;
}
export interface ApplyVTFxCaseCallback {
    (error: Error | null, model: RemoteModel, info: OpenModelInfo | null): void;
}
/**
 * Interface for callback that is called when a server update has completed
 *
 * @param error Error object containing error message, if any.
 */
export interface ServerUpdateCompletedCallback {
    (error: Error | null, model: RemoteModel): void;
}
/**
 * A callback that will be called when the streaming of the RemoteModel is complete, that is the client has all the information needed
 * to render the remote model in full resolution.
 *
 * You can register to receive a callback with the {@link RemoteModel.setOneShotDataStreamingCompleteCallback} method.
 */
export interface DataStreamingCompleteCallback {
    (model: RemoteModel): void;
}
/**
 * The handler that is called whenever the range of a result changes.
 *
 * This will be called when a result is loaded for the first time and when the time step is changed.
 *
 * It might be useful for updating a UI, for example the minimum and maximum values on a slider for an isosurface.
 */
export interface ResultRangeChangedHandler {
    (model: RemoteModel): void;
}
/**
 * The handler that is called whenever an error packet is received from the server.
 *
 * @param err Error object containing the error message.
 */
export interface ServerErrorHandler {
    (err: Error, model: RemoteModel): void;
}
/**
 *  Information about what was hit during a {@link RemoteModel.rayIntersect} call
 */
export interface RayIntersectResult {
    /**
     * The RemoteModel that was hit
     */
    model: RemoteModel;
    /**
     * Specification of what was hit inside the RemoteModel
     */
    hitItem: HitItem;
}
/**
 * A callback function invoked when the result of a {@link RemoteModel.rayIntersect} call is ready.
 *
 * The parameter provided to this function contains a {@link HitItem} which provides server-side information
 * about the hit on the remote model.
 */
export interface RayIntersectCallback {
    (intersectResult: RayIntersectResult): void;
}
/**
 * Status of the server communication
 */
export enum StreamingStatus {
    /**
     * The client model is non-existing or out-of-date, and needs data streamed from the server
     */
    DATA_STREAMING_NOT_STARTED = 0,
    /**
     * The client is receiving 3d data from the server
     */
    STREAMING_DATA = 1,
    /**
     * The client is up-to-date, no data needed from the server
     */
    DATA_STREAMING_COMPLETE = 2
}
/**
 * Interface describing progress data. Used in {@link ProgressHandler}
 */
export interface ProgressData {
    /**
     *
     */
    streamingStatus: StreamingStatus;
    /**
     * The percentage of work completed (0..100)
     */
    pctDone: number;
    /**
     * The percentage of data loaded out of the total data volume needed for the current model specification (0..100)
     */
    pctTotalDataComplete: number;
    /**
     * Message useful for debugging.
     */
    debugMessage: string | null;
}
/**
 * Progress event handler function that will be called whenever there is communication between the
 * client and the server.
 */
export interface ProgressHandler {
    (progressData: ProgressData): void;
}
export interface PollForDataSourceChangesInfo {
    model: RemoteModel;
    resultModified: boolean;
    transformationResultModified: boolean;
    geometryModified: boolean;
    modelDirectoryChanged: boolean;
}
/**
 * Callback that is invoked when polling for data source changes is complete.
 */
export interface PollForDataSourceChangesCallback {
    /**
     * @param error Error object containing the error message. Null on no errors.
     * @param info Information about what has changed in the data source.
     */
    (error: Error | null, info: PollForDataSourceChangesInfo): void;
}
/**
 * Response from the data source (Data Provider)
 *
 * Contains the string data sent from the provider as well as changeInfo which indicates what (if anything)
 * has changed in the data provider (similar to pollForDataSourceChanges())
 */
export interface DataSourceResponse {
    stringData: string;
    changeInfo?: PollForDataSourceChangesInfo;
}
/**
 * Callback that is invoked when executeDataSourceRequest() is complete.
 */
export interface DataSourceRequestCallback {
    /**
     * @param error Error object containing the error message. Null on no errors.
     * @param response The response from the data source (Data Provider). Will be null if there is an error.
     */
    (error: Error | null, response: DataSourceResponse): void;
}
/**
 * Callback that is invoked when the send to cloud is completed.
 *
 * If successful, the modelUrl will contain the URL to the shared model
 */
export interface SendToCloudCallback {
    /**
     * @param error Error object containing the error message. Null on no errors.
     * @param modelUrl The URL to the shared model.
     */
    (error: Error | null, modelUrl: string): void;
}
/**
 * Configuration of the SendToCloud operation
 */
export interface SendToCloudConfig {
    /**
     * URL to the cloud sharing portal. If blank, https://cloud.ceeetron.com will be used
     */
    cloudPortalUrl: string;
    /**
     * The users Upload ID on the cloud service. This is required for all uploads.
     */
    uploadId: string;
    /**
     * The name of the model on the cloud service.
     */
    caseName: string;
    /** Optional object with properties that will be appended as query parameters when uploading the model */
    additionalQueryParameters?: object;
}
/**
 * Performance data related to the communication between client and server.
 */
export interface CommunicationPerformanceData {
    /**
     * The type of action the performance data relates to.
     *
     * Possible values:
     *
     * - 'UpdateServerVisualization': Update the server with the current setting. This will prepare everything on the
     *   server side and send back the needed data pieces, but not the data itself.
     *
     * - 'ReqStepConfig': Used when having an animation. The server is already updated with regards to the display model,
     *   so GetStepConfig will query the data pieces needed the selected time step.
     *
     * - 'ReqDataPieces': Stream ready to send data pieces from the server to the client. The data payload of the
     *   3D Progressive object streaming
     */
    topic: string;
    /**
     * Round-trip time in milliseconds. This includes server processing time and data transfer time
     */
    roundTripTimeMS: number;
    /**
     * Optional time spent on the server. Applicable for UpdateServerVisualization and GetStepConfig topic.
     *
     * For the UpdateServerVisualization and GetStepConfig topic, a measure of the latency between
     * client and server could be estimated by looking at (roundTripTimeMS - serverElapsedTimeMS).
     */
    serverElapsedTimeMS?: number;
    /**
     * The amount of data in this transaction. This is applicable for ReqDataPieces.
     *
     * As there are very little sever processing time on ReqDataPieces, the bandwidth between client and server
     * can be estimated by dataSizeBytes/roundTripTimeMS, especially for larger data batches. The server
     * will request all data pieces in one call, so there is no round-trip time for each data piece.
     */
    dataSizeBytes?: number;
}
/**
 * Handler that is called whenever there is new communication performance info available.
 *
 * This handler is set with {@link RemoteModel.setCommunicationPerformanceHandler}
 *
 * See {@link CommunicationPerformanceData} for more information.
 */
export interface CommunicationPerformanceHandler {
    (info: CommunicationPerformanceData): void;
}
/**
 * Create, recreate or delete result calculator callback
 */
export interface CreateResultCalculatorCallback {
    (error: Error | null, model: RemoteModel): void;
}
/**
 * Definition of a result calculator used to initialize default calculators
 *
 * Note: This is used for calculators that require an init string and not automatically register a result
 */
export interface ResultCalculatorDefinition {
    calculatorId: string;
    resultIdString: string;
    initString: string;
    coordSystemString: string;
    paramsDict?: {
        [paramName: string]: number;
    };
}
/**
 * Configuration for creating or recreating result calculators
 */
export interface CreateResultCalculatorConfig {
    /** The ID of the calculator as provided in the CRC_FrameworkServices::registerCalculatorFunc() */
    calculatorId: string;
    /** The idString of the result to create. This should be unique. The idString of all results can be found in the ResultInfo of the result in the ModelDirectory */
    resultIdString: string;
    /** The initialization string passed to the CRCResultCalculator::initialize() method */
    initString: string;
    /**
     * (Optional) A string representing the coordinate system in the format "type=<type>;origin=<x,y,z>;orientation=<m00,m01,m02,m10,m11,m12,m20,m21,m22>".
     * Valid <type> values: "cartesian", "cylindrical", "spherical".
     * Orientation is a 3x3 rotation matrix specified in row-major order.
     * Example: "type=cylindrical;origin=10.0,5.0,0.0;orientation=1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0"
     */
    coordSystemString?: string;
}

/**
 * Specifies how inputs to a query are to be interpreted
 */
export enum RemoteQueryInputIdentType {
    /**
     * Interpret inputs as ids
     */
    ID = 0,
    /**
     * Interpret inputs as indices
     */
    INDEX = 1
}
/**
 * Base class for classes implementing queries to the RemoteModel on the CAE server.
 *
 * Since the majority of the CAE data for a RemoteModel is kept on the UgServer, we have several
 * queries to get information about the CAE data model from the client.
 *
 * Here is a list of the supported queries in the RemoteModel:
 *
 * -  QueryGeometryStatistics: Get statistics for a geometry or one part, such as element counts by type, node count, etc
 * -  QueryElementInfo: Get information about elements for a given frame or all frames
 * -  QueryNodeInfo:  Get information about nodes for a given frame or all frames
 * -  QuerySetItems: Get all the items in a given set, optionally with the tesselation of the set items
 * -  QuerySurfacePath: Get the path on the surface between the given points optionally with a sampled scalar result
 * -  QueryBulkCalculation: Calculation of bulk values (aggregated values) from cutting planes and visible surfaces of parts
 * -  QueryFeatureExtraction: Get the geometry and results of a feature extraction item (cutting plane, isosurface, isovolume)
 * -  QueryPartNodes: Get all nodes of a given part in a given frame
 * -  QueryPartSurfacePositions: Get information about positions on the visible surface of a part
 * -  QueryPartResults: Get information about results of a specific part
 * -  QueryResultMinMax: Get min/max values for a result based on the currently loaded states.
 * -  QueryNodeScalarResult: Get a scalar result for a given node across all states. Returns a time history series for one node
 * -  QueryGlobalNodePositionsForFrames: Get the global position of a given node(s) in a given frame(s)
 * -  QueryMapResultOnPoints: Get the scalar or vector result in a given set of points
 * -  QueryAllElementResultsForFrame: Get element results and element centroids for all elements in a given frame
 * -  QueryNamedGeneric: Generic query provided as a framework for customized queries
 */
export abstract class RemoteQuery {
}

/**
 * The color scheme to use when displaying scalar fringes (filled contours).
 *
 * This enum specifies how to create the colors to be used when mapping scalar results onto
 * model surfaces, cutting planes, isosurfaces and particle traces.
 */
export enum ColorScheme {
    /** Normal */
    NORMAL = 0,
    /** Normal inverted */
    NORMAL_INVERTED = 1,
    /** Black to white */
    BLACK_TO_WHITE = 2,
    /** White to black */
    WHITE_TO_BLACK = 3,
    /** Green to brown */
    GREEN_TO_BROWN = 4,
    /** White to brown */
    WHITE_TO_BROWN = 5,
    /** Metal casting */
    METAL_CASTING = 6,
    /** Thermal 1 */
    THERMAL_1 = 7,
    /** Thermal 2 */
    THERMAL_2 = 8,
    /** Thermal 3 */
    THERMAL_3 = 9,
    /** Viridis */
    VIRIDIS = 10,
    /** Turbo */
    TURBO = 11,
    /** Cool to Warm */
    COOL_TO_WARM = 12,
    /** Custom */
    CUSTOM = 13
}
export enum AutoRangeMode {
    /**
     * The auto full range will be computed from all items in the model
     */
    ALL_ITEMS = 0,
    /**
     * The auto full range will be computed only from the visible items in the model
     */
    VISIBLE_ITEMS = 1
}
export enum LegendColorMarkerPosition {
    /**
     * The Legend color marker will appear above the legend's main markers
     */
    ABOVE = 0,
    /**
     * The Legend color marker will appear below the legend's main markers
     */
    BELOW = 1
}
/**
 * Additional color legend marker for above, below and undefined colors
 *
 * Used by the {@link ScalarSettings.colorMarkerArray} property
 */
export interface LegendColorMarker {
    /**
     * Whether the marker should appear above or below the main markers in the color legend
     */
    position: LegendColorMarkerPosition;
    /**
     * The marker's color
     */
    color: Color3Like;
    /**
     * The marker's description
     */
    description: string;
}
export enum LegendVisibilityMode {
    /**
     * Always hide the color legend for this result
     */
    NEVER = 0,
    /**
     * Show the color legend for this result if used by any visible parts in the view (default)
     */
    AUTO = 1,
    /**
     * Always show the color legend for this result, no matter if it is in use or not
     */
    ALWAYS = 2
}
/**
 * Specification of how to render scalar results on the model, on cutting planes, on isosurfaces and on particle traces.
 *
 * Use this object to control the visual appearance of scalar results in the 3D viewer. You can specify
 * which {@link colorScheme} to use for the color legend and how many levels (unique colors) it should have with {@link levelCount}.
 * You can also control the legend's scaling, either by using {@link autoRangeMode} or by specifying {@link rangeMinimum} and {@link rangeMaximum}.
 *
 * **Example:** Setup a custom color legend
 *
 *```javascript
 * var modelSpec = myModel.modelSpec;
 *
 * var resultId = modelSpec.fringesResultId;
 * if (resultId >= 0) {
 *     var scalarSettings = myModel.getScalarSettingsById(resultId);
 *
 *     var min = myModel.getScalarResultMinimumValue(resultId);
 *     var max = myModel.getScalarResultMaximumValue(resultId);
 *     var range = max - min;
 *
 *     // Setup custom scale 50% -> 100% of the range using a green to brown legend.
 *     scalarSettings.setRange(min + range*0.5, max);
 *     scalarSettings.colorScheme = cee.ug.ColorScheme.WHITE_TO_BROWN;
 *     scalarSettings.levelCount = 3;
 * }
 *```
 *
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/ScalarSettings_custom.png)
 *
 */
export class ScalarSettings {
    /**
     *
    */
    private constructor();
    /**
     * The id (>=0) of the scalar result. This id corresponds to the id in {@link ModelDirectory.scalarResultArray}.
     */
    get resultId(): number;
    /**
     * The minimum range of the scalar result if auto range is disabled. This is undefined if auto range is enabled.
     *
     * To set a manual range, use the {@link setRange} function.
     */
    get rangeMinimum(): number | undefined;
    /**
     * The maximum range of the scalar result if auto range is disabled. This is undefined if auto range is enabled.
     *
     * To set a manual range, use the {@link setRange} function.
     */
    get rangeMaximum(): number | undefined;
    /**
     * Whether auto range is enabled.
     */
    get isAutoRangeEnabled(): boolean;
    /**
     * Auto range mode. Set this value with {@link setAutoRange}.
     *
     * To disable auto range, set a manual range with {@link setRange}.
     */
    get autoRangeMode(): AutoRangeMode;
    /**
     * If true, a logarithmic range will be used for the color legend and results mapping.
     * If false, a linear mapping will be used.
     */
    get logarithmicMapping(): boolean;
    /**   */
    set logarithmicMapping(logarithmicMapping: boolean);
    /**
     * Specify if the scalar result should be shown as a node averaged result or not.
     *
     * If false (default) the result is shown as is computed. If true, a node averaged result will be shown
     * that is derived from the original result.
     *
     * Also, setting this value for a result used to compute a feature extraction (like isovolume)
     * affects the way the feature extraction is generated. For example, for per-element result mapping,
     * the isosurface will be generated as a smooth node-averaged surface when this is set to true, instead of the usual "blocky" appearance.
     */
    get nodeAveragedValues(): boolean;
    set nodeAveragedValues(useNodeAveraging: boolean);
    /**
     * The color scheme to use for the color legend and mapped colors on the model.
     *
     * Use this property to set the color scheme to any of the pre-defined color schemes.
     *
     * The colorScheme cannot be set to CUSTOM with this property. This is done with the
     * setCustomContinuousColorArr() method or customFilledContoursColorArr property. colorScheme will
     * return CUSTOM if one if these setters are used.
     *
     * Note: Changing the colorScheme will set {@link aboveRangeColor} and {@link belowRangeColor} to null.
     */
    get colorScheme(): ColorScheme;
    set colorScheme(colorScheme: ColorScheme);
    /** Setup the color legend with the given level colors.
     *
     * The color scheme will be set to CUSTOM, and the number of levels will be set to the length of
     * the provided array.
     */
    get customFilledContoursColorArr(): Color3Like[];
    set customFilledContoursColorArr(colorArr: Color3Like[]);
    /** Get the colors of the current color legend (if in levels mode)
     *
     * If levelCount > 0, this will return the colors for each level on the color legend, starting from
     * the bottom of the legend.
     *
     * Note: If not using customFilledContoursColorArr, the color legend info needs to be received from the server
     * before this method will return valid info, so make sure the current update of display model is fully completed.
     */
    get filledContoursColorArr(): Color3Like[];
    /**
     * Get the custom continuous color array if defined.
     *
     * This is setup with the setCustomContinuousColorArr() method.
     */
    get customContinuousColorArr(): Color3Like[];
    /**
     * Get the custom continuous value array if defined.
     *
     * This is setup with the setCustomContinuousColorArr() method.
     */
    get customContinuousValueArr(): number[];
    /**
     * Sets custom color scheme for a continuous color legend.
     *
     * Specify an array of colors to use to create the interpolated continuous legend.
     *
     * If values are specified (valueArr) the color will be set at that value and interpolated
     * between the values. If no values are provided the specified colors will be distributed
     * evenly between min and max.
     *
     * The range will be adjusted if needed to include the specified values (if any).
     *
     * Please note that there is no correlation between the values specified and the tick marks on the
     * legend. The values specify the position of the color on the legend. The tick marks will be
     * distributed on round numbers.
     *
     * Note! colorScheme will be set to ColorScheme.CUSTOM and the levelCount to 0.
     */
    setCustomContinuousColorArr(colorArr: Color3Like[], valueArr?: number[]): void;
    /**
     * Get the custom continuous tick mark array if defined.
     *
     * This is setup with the setCustomContinuousTickMarks() method.
     */
    get customContinuousTickMarkArr(): number[];
    /**
     * Set custom tick marks for a continuous color legend. Any values outside the legend min/max range
     * will be ignored.  If an empty array or falsy value is provided, the tick marks will be distributed
     * on round numbers by default.
     *
     * Note this will not set the legend to be continuous. To do that, set levelCount to 0.
     */
    setCustomContinuousTickMarks(tickMarkValues: number[]): void;
    /**
     * The color for the parts of the model that are above the current range.
     *
     * Default is null, which means that the top color of the {@link colorScheme} will be used.
     *
     * Note: Changing the colorScheme will set {@link aboveRangeColor} and {@link belowRangeColor} to null.
     */
    get aboveRangeColor(): Color3Like | null;
    set aboveRangeColor(color: Color3Like | null);
    /**
     * The color for the parts of the model that are below the current range.
     *
     * Default is null, which means that the bottom color of the {@link colorScheme} will be used.
     *
     * Note: Changing the colorScheme will set {@link aboveRangeColor} and {@link belowRangeColor} to null.
     */
    get belowRangeColor(): Color3Like | null;
    set belowRangeColor(color: Color3Like | null);
    /**
     * The color of the parts of the model with an undefined result.
     */
    get undefinedColor(): Color3Like;
    set undefinedColor(color: Color3Like);
    /**
     * The number of levels (unique colors) in the color legend.
     *
     * If you want a continuous (smooth) legend, set the number of levels to 0. This will create a continuous legend
     * with tick marks at round numbers.
     */
    get levelCount(): number;
    set levelCount(numLevels: number);
    /**
     * Constant scaling term used for custom scaling of the legend.
     *
     * The value shown on the legend tick marks is:
     *
     * ```
     * legendValue = scalingConstantTerm + scalarValue*scalingFirstDegreeTerm
     * ```
     */
    get scalingConstantTerm(): number;
    set scalingConstantTerm(scalingConstantTerm: number);
    /**
     *  First degree term used for custom scaling of the legend.
     *
     * The value shown on the legend tick marks is:
     *
     * ```
     * legendValue = scalingConstantTerm + scalarValue*scalingFirstDegreeTerm
     * ```
     */
    get scalingFirstDegreeTerm(): number;
    set scalingFirstDegreeTerm(scalingFirstDegreeTerm: number);
    /**
     * The numerical format to use for the numbers on the color legend tick marks
     *
     * Legal options:
     * 'g': (default) (using the .toPrecision JS function).
     * 'f': fixed notation (1234.0) (using the .toFixed() JS function)
     * 'e': scientific notation (1.234e4)  (using the .toExponential JS function)
     *
     * The precision is controlled by the numericPrecision property.
     */
    get numericFormat(): string;
    set numericFormat(numericFormat: string);
    /**
     * Set the precision to use for the numbers on the color legend tick marks
     *
     * See numericFormat for the different options.
     */
    get numericPrecision(): number;
    set numericPrecision(precision: number);
    /**
     * Additional color legend markers that can be shown above or below the main markers in the legend.
     *
     * Useful for describing above, below and undefined colors.
     *
     * Example: Add a "No result" marker below the color legend:
     * ```javascript
     * scalarSettings.colorMarkerArray = [
     *     {
     *         position: cee.ug.LegendColorMarkerPosition.BELOW,
     *         color: new cee.Color3(0.5, 0.5, 0.5),
     *         description: "No result"
     *     }
     * ];
     * ```
     */
    get colorMarkerArray(): ReadonlyArray<LegendColorMarker>;
    set colorMarkerArray(colorMarkers: ReadonlyArray<LegendColorMarker>);
    /**
     * Specifies the visibility of the color legend.
     *
     * The legend can be set to appear if used by any part in the model (AUTO, default), to always be
     * shown (ALWAYS) or to never be shown (NEVER)
     */
    get legendVisibilityMode(): LegendVisibilityMode;
    set legendVisibilityMode(mode: LegendVisibilityMode);
    /**
     * Whether filtering of this scalar result is enabled.
     */
    get isFilteringEnabled(): boolean;
    /**
     * The minimum value the result needs to have to be visible when filtering is enabled. This will be undefined if filtering is disabled.
     */
    get filteringRangeMinimum(): number | undefined;
    /**
     * The maximum value the result needs to have to be visible when filtering is enabled. This will be undefined if filtering is disabled.
     */
    get filteringRangeMaximum(): number | undefined;
    /**
     * Sets a user defined range of the scalar result.
     *
     * This function will disable auto range.
     */
    setRange(min: number, max: number): void;
    /**
     * Sets the automatic full range of the scalar result.
     *
     * Set this to AutoRangeMode.ALL_ITEMS to use the full range for the result (this is the default) or
     * to AutoRangeMode.VISIBLE_ITEMS to limit the range to the currently visible parts
     */
    setAutoRange(mode: AutoRangeMode): void;
    /**
     * Specifies to show only the results whose value lies within the given range.
     *
     * When enabled, only results whose value is within the given filter range <`minValue`, `maxValue`> will be drawn.
     * All other results will be discarded and not drawn.
     *
     * The filtering will be done on a per-element basis, so an element (and thus all its surface) is either fully visible or not visible.
     * If you have a per-node or per-element-node result, the element is visible if at least one of the nodes is within range.
     */
    setFilteringRange(minValue: number, maxValue: number): void;
    /**
     * Disables any filtering of the results.
    */
    disableFiltering(): void;
    /**
     * Maps the given domain value to a color using the current scalar settings
     */
    mapToColor(scalarValue: number): Color3Like;
    /**
     * Gets the settings for this object as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): ScalarSettingsProperties;
    /**
     * Applies the settings in the given properties object to this scalar settings
     */
    setFromProperties(props: Partial<ScalarSettingsProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link ScalarSettings}
 */
export interface ScalarSettingsProperties {
    /**
     * See {@link ScalarSettings.resultId}
     */
    resultId: number;
    /**
     * See {@link ScalarSettings.autoRangeMode}
     */
    autoRangeMode: AutoRangeMode;
    /**
     * See {@link ScalarSettings.rangeMinimum}
     */
    rangeMinimum: number | undefined;
    /**
     * See {@link ScalarSettings.rangeMaximum}
     */
    rangeMaximum: number | undefined;
    /**
     * See {@link ScalarSettings.logarithmicMapping}
     */
    logarithmicMapping: boolean;
    /**
     * See {@link ScalarSettings.nodeAveragedValues}
     */
    nodeAveragedValues: boolean;
    /**
     * See {@link ScalarSettings.colorScheme}
     */
    colorScheme: ColorScheme;
    /**
     * See {@link ScalarSettings.aboveRangeColor}
     */
    aboveRangeColor: Color3Like | null;
    /**
     * See {@link ScalarSettings.belowRangeColor}
     */
    belowRangeColor: Color3Like | null;
    /**
     * See {@link ScalarSettings.undefinedColor}
     */
    undefinedColor: Color3Like;
    /**
     * See {@link ScalarSettings.customFilledContoursColorArr}
     */
    customFilledContoursColorArr: Color3Like[];
    /**
     * See {@link ScalarSettings.levelCount}
     */
    levelCount: number;
    /**
     * See {@link ScalarSettings.customContinuousColorArr}
     */
    customContinuousColorArr: Color3Like[];
    /**
     * See {@link ScalarSettings.customContinuousValueArr}
     */
    customContinuousValueArr: number[];
    /**
     * See {@link ScalarSettings.customContinuousTickMarkArr}
     */
    customContinuousTickMarkArr: number[];
    /**
     * See {@link ScalarSettings.scalingConstantTerm}
     */
    scalingConstantTerm: number;
    /**
     * See {@link ScalarSettings.scalingFirstDegreeTerm}
     */
    scalingFirstDegreeTerm: number;
    /**
     * See {@link ScalarSettings.numericFormat}
     */
    numericFormat: string;
    /**
     * See {@link ScalarSettings.numericPrecision}
     */
    numericPrecision: number;
    /**
     * See {@link ScalarSettings.colorMarkerArray}
     */
    colorMarkerArray: LegendColorMarker[];
    /**
     * See {@link ScalarSettings.legendVisibilityMode}
     */
    legendVisibilityMode: LegendVisibilityMode;
    /**
     * See {@link ScalarSettings.setFilteringRange}
     */
    enableFiltering: boolean;
    /**
     * See {@link ScalarSettings.filteringRangeMinimum}
     */
    filteringRangeMinimum: number | undefined;
    /**
     * See {@link ScalarSettings.filteringRangeMaximum}
     */
    filteringRangeMaximum: number | undefined;
}

/** @module cee.ug */ /** */
/**
 * Client-side visible triangle picker. This class can be used to get triangles that are currently visible
 * in the view, either within a specified rectangular region or at specified points.
 *
 * Use {@link RemoteModel.createTrianglePicker} to create instances of this class.
 *
 * It is the programmer's responsibility to call {@link destroy} on pickers that are no longer needed, in order to
 * release resources.
 *
 * Note that a TrianglePicker is only valid while the model is in the same state as when the
 * picker was created. A new picker must be created whenever any display properties are changed on the model, such as
 * current frame or draw style.
 */
export class TrianglePicker {
    /**
     * Returns visible triangles currently located within the given rectangular region of the view
     *
     * @param cssPixCoordX The left side of the rectangle in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param cssPixCoordY The top side of the rectangle in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param width The width of the rectangle in css pixels
     * @param height The height of the rectangle in css pixels
     *
     * Note that the coordinates are relative to the top left corner of the Canvas element, as in the
     * MouseEvent.offsetX/offsetY if the target of the event is the Canvas Element.
     *
     * If using multiple Views, they will not be local to the given View the TrianglePicker belongs to, but
     * to the parent Viewer.
     */
    getVisibleTrianglesInRectangle(cssPixCoordX: number, cssPixCoordY: number, width: number, height: number): ClientSideHitItem[];
    /**
     * Returns visible triangles currently located at the specified points in the view
     *
     * @param cssPixCoords Points in canvas offset css coordinates. These are relative to the top
     *               left corner of the Canvas element (like MouseEvent.offsetX/Y).
     *
     * Note that the coordinates are relative to the top left corner of the Canvas element, as in the
     * MouseEvent.offsetX/offsetY if the target of the event is the Canvas Element.
     *
     * If using multiple Views, they will not be local to the given View the TrianglePicker belongs to, but
     * to the parent Viewer.
     */
    getVisibleTrianglesAtPoints(cssPixCoords: Vec2Like[]): ClientSideHitItem[];
    /**
     * Release WebGL resources. Once called this object can no longer be used.
     */
    destroy(): void;
}

/** @module cee.ug */ /** */
/**
 * Type of result
 */
export enum ResultType {
    /** Scalar result */
    SCALAR = 0,
    /** Vector result */
    VECTOR = 1,
    /** Displacement result */
    DISPLACEMENT = 2,
    /** Symmetric tensor result */
    SYMMETRIC_TENSOR = 3
}
/**
 * Result position (mapping) of a result
 */
export enum ResultMapping {
    /** One result per node in the part. */
    PER_NODE = 0,
    /** One result per element in the part. */
    PER_ELEMENT = 1,
    /** One result per element node in the part. */
    PER_ELEMENT_NODE = 2,
    /** One result per element surface in the part. */
    PER_SURFACE = 3
}
/**
 * Object type.
 */
export enum ObjectType {
    /** Normal (FEA) part */
    PART = 0,
    /** Cutting plane */
    CUTTING_PLANE = 1,
    /** Isosurface */
    ISOSURFACE = 2,
    /** Isovolume */
    ISOVOLUME = 3
}
/**
 * Interface for identifying a node in a geometry. Nodes are uniquely defined by geometry index, part id and node index.
 */
export interface NodeIdent {
    /**
     * The index of the geometry the node belongs to.
     */
    geometryIndex: number;
    /**
     * The id of the part the node belongs to.
     */
    partId: number;
    /**
     * The index of the node.
     */
    nodeIndex: number;
}

/**
 * The color mode for vector arrows.
 */
export enum VectorColorMode {
    /**
     * Color vector arrows with single color
     */
    SINGLE = 0,
    /**
     * Take color from the scalar on the object on which the vector is mapped
     */
    COLOR_BY_FRINGES = 1,
    /**
     * Take color from the scalar values referenced by the provided scalar result ID.
     * The desired scalar ID must be set with {@link VectorSettings.mapScalarResultId}.
     */
    COLOR_BY_MAP_SCALAR = 2
}
/**
 * Scaling mode to use for vectors.
 */
export enum VectorScaleMode {
    /**
     * Absolute scaling of vectors. Vectors will be scaled by the specified factor and rendered in world coordinates.
     */
    ABSOLUTE_SCALING = 0,
    /**
     * Relative scaling of vectors. Vectors will be scaled relative to the current model's bounding box. For example, a factor of 0.1 means that
     * the length of the longest vector in the result will be 10% of the current model's bounding box extent.
     */
    RELATIVE_SCALING = 1
}
/**
 * Vector visual representation types
 */
export enum VectorType {
    /**
     * A normal vector arrow (default)
     */
    ARROW = 0,
    /**
     * A vector centered in the node/vertex, with arrow heads pointing outwards in both directions
     */
    SYMMETRIC_ARROW = 1,
    /**
     * A vector centered in the node/vertex, with arrow heads pointing inward in both directions
     */
    REVERSE_SYMMETRIC_ARROW = 2,
    /**
     * A vector centered in the node/vertex, with arrow heads pointing either inwards or outwards
     * depending on sign of scalar value
     */
    DYNAMIC_SYMMETRIC_ARROW = 3
}
/**
 * Render modes for vectors
 */
export enum VectorDrawMode {
    /**
     * Default mode where the vector is drawn as 3D arrows
     */
    NORMAL = 0,
    /**
     * A simplified unlit mode where the vector is drawn as a simplified geometry
     */
    SIMPLE = 1
}
/**
 * Specification of how to render vector arrows for the given result on the model, on cutting planes
 * and on isosurfaces.
 *
 * Use this object to control the visual appearance of vector arrows in the 3D viewer. With {@link colorMode} you can specify whether
 * vectors should use a {@link singleVectorColor}, the color mapping from the object's scalar fringes, or the color mapping from a
 * provided scalar result ID. You can also setup relative or absolute scaling with {@link scaleMode} and perform filtering and clamping
 * of the vector magnitudes (lengths), with {@link setFilteringRange} and {@link setClampingRange} respectively.
 */
export class VectorSettings {
    /**
     *
    */
    private constructor();
    /**
     * The id (>=0) of the vector result. This id corresponds to the id in {@link ModelDirectory.vectorResultArray}.
     */
    get resultId(): number;
    /**
     * The scaling mode to use for the vector arrows (absolute or relative).
     */
    get scaleMode(): VectorScaleMode;
    /**   */
    set scaleMode(scaleMode: VectorScaleMode);
    /**
     * The scaling factor to use for the vector arrows. This factor is interpreted as either absolute or relative based on
     * {@link scaleMode}. Returns undefined if {@link anisotropicScaleFactor} is set and in use.
     */
    get scaleFactor(): number | undefined;
    /**   */
    set scaleFactor(scaleFactor: number);
    /**
     * The anisotropic scaling factor to use for the vector arrows. The provided value will scale each vector
     * result component by the respective scaling factor. This factor is interpreted as either absolute or relative based on
     * {@link scaleMode}. Returns null if {@link scaleFactor} is set and in use (default).
     */
    get anisotropicScaleFactor(): Vec3Like | null;
    /**   */
    set anisotropicScaleFactor(anisotropicScaleFactor: Vec3Like);
    /**
     * The coloring mode of the vector arrows. This can be either single color, as specified by {@link singleVectorColor},
     * color by fringes, where the color is taken from the scalar result in the object on which the vector arrows are mapped,
     * or color by a given result ID, where the color is taken from the scalar results referenced by {@link mapScalarResultId}.
     */
    get colorMode(): VectorColorMode;
    /**   */
    set colorMode(colorMode: VectorColorMode);
    /**
     * The color to use for the vectors if {@link colorMode} is SINGLE.
     */
    get singleVectorColor(): Color3Like;
    set singleVectorColor(singleColor: Color3Like);
    /**
     * The scalar results ID to reference for coloring vectors if {@link colorMode} is COLOR_BY_MAP_SCALAR.
     */
    get mapScalarResultId(): number;
    set mapScalarResultId(scalarResultId: number);
    /**
     * The visualization type for the vector result. Use the methods {@link setVectorTypeArrow}, {@link setVectorTypeSymmetricArrow}
     * etc to set this property.
     */
    get vectorType(): VectorType;
    /**
     * Set the visualization type to ARROW - normal arrows.
     */
    setVectorTypeArrow(): void;
    /**
     * Set the visualization type to SYMMETRIC_ARROW - arrows centered on the node/vertex, with arrow heads pointing
     * outwards in both directions
     */
    setVectorTypeSymmetricArrow(): void;
    /**
     * Set the visualization type to REVERSE_SYMMETRIC_ARROW - arrows centered on the node/vertex, with arrow heads
     * pointing inward in both directions
     */
    setVectorTypeReverseSymmetricArrow(): void;
    /**
     * Set the visualization type to DYNAMIC_SYMMETRIC_ARROW - arrows centered on the node/vertex, with arrow head directions
     * determined by the sign of the scalar value at that point.
     *
     * Note that for mapped vectors on cutting planes, isosurfaces and isovolumes, if dynamicSymmetricArrows scalar does not
     * match the scalar mapped to the cutting plane/isosurface/isovolume, then the vectors will not be displayed.
     *
     * @param scalarId The id of the scalar to use to determine arrow directions.
     */
    setVectorTypeDynamicSymmetricArrow(scalarId: number): void;
    /**
     * The rendering mode for the vector result.
     *
     * Vectors can either be drawn as 3D arrows (default) or a simplified version
     */
    get drawMode(): VectorDrawMode;
    set drawMode(drawMode: VectorDrawMode);
    /**
     * The radius of the vector arrow shaft relative to the vector length.
     */
    get arrowShaftRelativeRadius(): number;
    set arrowShaftRelativeRadius(shaftRelativeRadius: number);
    /**
     * The radius of the vector arrow head relative to the vector length.
     */
    get arrowHeadRelativeRadius(): number;
    set arrowHeadRelativeRadius(headRelativeRadius: number);
    /**
     * The length of the vector arrow head relative to the vector length.
     */
    get arrowHeadRelativeLength(): number;
    set arrowHeadRelativeLength(headRelativeLength: number);
    /**
     * The id of the scalar result used to determine directions of dynamic symmetric arrows. Use
     * {@link setVectorTypeDynamicSymmetricArrow} to set this value.
     */
    get dynamicSymmetricArrowsScalarId(): number;
    /**
     * Set if the vectors should be projected onto the model surface or not (default is false)
     *
     * If set to true, all vectors are projected onto the surface using the surface normal in that point
     * to define the plane to project onto.
     *
     * This works in the similar way to the CuttingPlane::setProjectVectorsOnPlane() method.
     *
     * NOTE: It is only in effect when having PER_NODE and PER_ELEMENT_NODE vector results
     */
    get projectVectorsOnSurface(): boolean;
    set projectVectorsOnSurface(project: boolean);
    /**
     * Whether clamping of this vector result is enabled.
     */
    get isClampingEnabled(): boolean;
    /**
     * The minimum length the vectors will have if clamping is enabled. This will be undefined if clamping is disabled.
     */
    get clampingRangeMinimum(): number | undefined;
    /**
     * The maximum length the vectors will have if clamping is enabled. This will be undefined if clamping is disabled.
     */
    get clampingRangeMaximum(): number | undefined;
    /**
     * Whether filtering of this vector result is enabled.
     */
    get isFilteringEnabled(): boolean;
    /**
     * The minimum length the vectors need to have to be visible when filtering is enabled. This will be undefined if filtering is disabled.
     */
    get filteringRangeMinimum(): number | undefined;
    /**
     * The maximum length the vectors need to have to be visible when filtering is enabled. This will be undefined if filtering is disabled.
     */
    get filteringRangeMaximum(): number | undefined;
    /**
     * Specify if the vector result should be shown as a node averaged result or not.
     *
     * If false (default) the result is shown as is computed. If true, a node averaged result will be shown
     * that is derived from the original result.
     */
    get nodeAveragedValues(): boolean;
    set nodeAveragedValues(useNodeAveraging: boolean);
    /**
     * Specifies to clamp all vectors between the given min and max length.
     *
     * When enabled, all vectors will be clamped into the given <clampMinLength, clampMaxLength> range. So if clampMinLength = clampMaxLength, all
     * vectors will be drawn with the same length, regardless of the magnitude of the vector.
     *
     * Note: The clamping is done before any scaling.
     */
    setClampingRange(clampMinLength: number, clampMaxLength: number): void;
    /**
     * Disables any clamping of the vectors. They will be rendered with the length specified by the vector result and scaling.
    */
    disableClamping(): void;
    /**
     * Specifies to show only the vectors whose length lies within the given range.
     *
     * When enabled, only vectors whose length is within the given filter range <filterMinLength, filterMaxLength> will be drawn.
     * All other vectors will be discarded and not drawn.
     *
     * Note: The filtering is done before any scaling.
     */
    setFilteringRange(minLength: number, maxLength: number): void;
    /**
     * Disables any filtering of the vectors. They will be rendered with the length specified by the vector result and scaling.
    */
    disableFiltering(): void;
    /**
     * Get number of vectors to skip between each vector that is drawn. Default 0.
     *
     * If set > 0, will draw every n'th vector. No guarantee of an even distribution.
     */
    get drawSkipBy(): number;
    set drawSkipBy(skipBy: number);
    /**
     * If there are more vectors than specified with setDrawMaximumCount(), every n'th vector arrow will
     * be skipped to reduce the number of arrows to within maximum count.
     *
     * When set to 0, all vectors will be drawn
     *
     * Note! If drawSkipBy is set to value other than 0, this skip by value will be used and
     * maximum count ignored!
     */
    get drawMaxCount(): number;
    set drawMaxCount(skipBy: number);
    /**
     * Gets the settings for this object as a Plain Old JavaScript Object (POJO).
     */
    getAsProperties(): VectorSettingsProperties;
    /**
     * Applies the settings in the given properties object to this vector settings
     */
    setFromProperties(props: Partial<VectorSettingsProperties>): void;
}

/** @module cee.ug */ /** */
/**
 * Plain Old JavaScript Object (POJO) containing the properties of a {@link VectorSettings}
 */
export interface VectorSettingsProperties {
    /**
     * See {@link VectorSettings.resultId}
     */
    resultId: number;
    /**
     * See {@link VectorSettings.scaleMode}
     */
    scaleMode: VectorScaleMode;
    /**
     * See {@link VectorSettings.scaleFactor}
     */
    scaleFactor: number | undefined;
    /**
     * See {@link VectorSettings.anisotropicScaleFactor}
     */
    anisotropicScaleFactor: Vec3Like | null;
    /**
     * See {@link VectorSettings.colorMode}
     */
    colorMode: VectorColorMode;
    /**
     * See {@link VectorSettings.singleVectorColor}
     */
    singleVectorColor: Color3Like;
    /**
     * See {@link VectorSettings.mapScalarResultId}
     */
    mapScalarResultId: number;
    /**
     * See {@link VectorSettings.vectorType}
     */
    vectorType: VectorType;
    /**
     * See {@link VectorSettings.drawMode}
     */
    drawMode: VectorDrawMode;
    /**
     * See {@link VectorSettings.arrowShaftRelativeRadius}
     */
    arrowShaftRelativeRadius: number;
    /**
     * See {@link VectorSettings.arrowHeadRelativeRadius}
     */
    arrowHeadRelativeRadius: number;
    /**
     * See {@link VectorSettings.arrowHeadRelativeLength}
     */
    arrowHeadRelativeLength: number;
    /**
     * See {@link VectorSettings.setVectorTypeDynamicSymmetricArrow}
     */
    dynamicSymmetricArrowsScalarId: number;
    /**
     * See {@link VectorSettings.projectVectorsOnSurface}
     */
    projectVectorsOnSurface: boolean;
    /**
    * Whether to enable clamping, see {@link VectorSettings.setClampingRange}
    */
    enableClamping: boolean;
    /**
     * See {@link VectorSettings.clampingRangeMinimum}
     */
    clampingRangeMinimum: number | undefined;
    /**
     * See {@link VectorSettings.clampingRangeMaximum}
     */
    clampingRangeMaximum: number | undefined;
    /**
     * Whether to enable filtering, see {@link VectorSettings.setFilteringRange}
     */
    enableFiltering: boolean;
    /**
     * See {@link VectorSettings.filteringRangeMinimum}
     */
    filteringRangeMinimum: number | undefined;
    /**
     * See {@link VectorSettings.filteringRangeMaximum}
     */
    filteringRangeMaximum: number | undefined;
    /**
     * See {@link VectorSettings.drawSkipBy}
     */
    drawSkipBy: number;
    /**
     * See {@link VectorSettings.drawMaxCount}
     */
    drawMaxCount: number;
    /**
     * See {@link VectorSettings.nodeAveragedValues}
     */
    nodeAveragedValues: boolean;
}

/** @module cee.ug */ /** */
/**
 * Identifier for a visible object.
 */
export interface VisibleObjectItem {
    /**
     * Type of the object. See {@link ObjectType}.
     */
    objectType: ObjectType;
    /**
     * ID of the object. Part ID, cutting plane ID, etc.
     */
    objectId: number;
    /**
     * The geometry index of the Part.
     *
     * Only valid for {@link ObjectType.PART}. For other object types, this value is -1.
     */
    geometryIndex: number;
}
/**
 * Client-side visible object picker. This class can be used to get objects that are currently visible
 * in the view, within a specified rectangular region.
 *
 * Use {@link RemoteModel.createVisibleObjectPicker} to create instances of this class.
 *
 * It is the programmer's responsibility to call {@link destroy} on pickers that are no longer needed, in order to
 * release resources.
 *
 * Note that a VisibleObjectPicker is only valid while the model is in the same state as when the
 * picker was created. A new picker must be created whenever any display properties are changed on the model, such as
 * current frame or draw style, or when a new state is loaded.
 */
export class VisibleObjectPicker {
    /**
     * Returns visible objects currently located within the given rectangular region of the view
     *
     * @param cssPixCoordX The left side of the rectangle in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param cssPixCoordY The top side of the rectangle in css pixel coordinates. This is relative to the top
     *                left corner of the Viewer's Canvas element.
     * @param cssPixWidth The width of the rectangle in css pixels
     * @param cssPixHeight The height of the rectangle in css pixels
     *
     * Note that the coordinates are relative to the top left corner of the Canvas element, as in the
     * MouseEvent.offsetX/offsetY if the target of the event is the Canvas Element.
     *
     * If using multiple Views, they will not be local to the given View the VisibleObjectPicker belongs to, but
     * to the parent Viewer.
     */
    getVisibleObjectsInRectangle(cssPixCoordX: number, cssPixCoordY: number, cssPixWidth: number, cssPixHeight: number, acceptPartiallyContainedObjects: boolean): VisibleObjectItem[];
    /**
     * Release WebGL resources. Once called this object can no longer be used.
     */
    destroy(): void;
}

} // ug



//
// usg
// ===================================================================================
export namespace usg {

/** @module cee.usg */ /** */
/**
 * Settings for the displacement results in one model.
 *
 * These settings apply to all states in the model.
 *
 * You can get the settings for the displacements in an usg model with the
 * {@link UnstructGridModel.displacementSettings} property.
 */
export class DisplacementSettings {
    /**
     * The displacement scaling factor
     *
     * This factor will be multiplied with the x,y,z component of the displacement result before added
     * to the position of the geometry node.
     *
     * currentNode = geometry_node + scaleFactor*displacement_result
    */
    get scaleFactor(): number;
    set scaleFactor(scaleFactor: number);
}

/** @module cee.usg */ /** */
/**
 * Helper class for highlighting elements
 *
 * The class makes it easy to highlight an element by adding a tessellation of the element to a markup
 * model, as well as creating a label with the element id/index.
 *
 * ![](/images/UsgElementHighligher.png)
 */
export class ElementHighlighter {
    /**
     * Setup the object with the unstruct grid model with the FEA model, and the Markup Model which will
     * receive the highlight parts constructed from the usgModel.
    */
    constructor(usgModel: UnstructGridModel, markupModel: mrk.MarkupModel);
    /**
     * Add a part with the tessellation of the given element as a surface with the given color.
     * The part will use eye lift to not interfere with the usg model.
     *
     * See example image above for how it will look
    */
    addElementHighlight(surfaceColor: Color3, state: State, partIndex: number, elementIndex: number): boolean;
    addElementHighlight(surfaceColor: Color3, hitItem: HitItem): boolean;
    /**
     * Add an element label based on either a hit item or specified by state, part and element index.
     *
     * See example image above for how it will look
    */
    addElementLabel(state: State, partIndex: number, elementIndex: number, label: string): boolean;
    addElementLabel(hitItem: HitItem): boolean;
}

/** @module cee.usg */ /** */
/**
 * The geometry class defines a CAE surface geometry that can be used in one or more {@link State States}.
 *
 * A geometry has one or more {@link Part Parts}. Each part defines a mesh with surface elements and nodes, as well
 * as settings on how to render a part. There is no limit on the number of nodes per element. A mesh
 * can also be shared between parts (in the same or different geometries).
 *
 * The common case is to use one geometry for all states and then use displacements and/or
 * transformation results to animate the model. Scalar and vector results can also be defined per state.
 *
 * Example:
 ```javascript
 let model = new cee.usg.UnstructGridModel();
 this.m_view.addModel(model);
 this.m_view.background.setSingleColor({r: 1, g: 1, b:1, a: 1});

 let geometry = new cee.usg.Geometry();
 
 const vertexArr = [
     0,0,0,
     1,0,0, 1,3,0,
     2,0,0, 4,0,0, 3,3,0,
     5,0,0, 7,0,0, 7,3,0, 5,3,0,
     9,0,0, 10,0,0, 11,1,0, 11,2,0, 10,3,0, 9,3,0, 8,2,0, 8,1,0,
     12,0,0, 14,0,0, 16,0,0,
     12,3,0, 14,3,0, 16,3,0
 ];

 const elConnArr = [
     0,
     1,2,
     3,4,5,
     6,7,8,9,
     10,11,12,13,14,15,16,17,
     18,19,22,21,
     19,20,23,22
 ];

 const elNodeCountArr = [1, 2, 3, 4, 8, 4, 4];

 // Create the first part
 let part1 = geometry.addPart();
 part1.mesh = new cee.usg.Mesh(vertexArr, elNodeCountArr, elConnArr);
 part1.settings.color = new cee.Color3(1,0,0);

 // Create the second part - same mesh with transform
 let part2 = geometry.addPart();
 part2.mesh = part1.mesh;
 part2.settings.color = new cee.Color3(0,1,0);
 part2.settings.drawStyle = cee.usg.DrawStyle.SURFACE_MESH;

 // Create a state, set the geometry and add the scalar result
 let state = model.addState();
 state.geometry = geometry;

 // Transform the second part
 state.setPartTransformationAt(1, cee.Mat4.fromTranslation(new cee.Vec3(0,5,0)));
 ```
 *
 * This code sample produces the following image in the 3D Viewer:
 * ![](/images/UsgGeometry.png)
 */
export class Geometry {
    /**
     * The number of parts in the model.
     */
    get partCount(): number;
    /**
     * Returns a read only array with all parts
     */
    getPartArray(): ReadonlyArray<Part>;
    /**
     * Creates a new part and adds it to the geometry.
     *
     * Returns the newly created part.
     */
    addPart(): Part;
    /**
     * Returns an active reference to the part at the given (zero based) index.
     */
    getPartAt(partIndex: number): Part;
    /**
     * Delete the part at the given zero based index
     */
    deletePartAt(partIndex: number): void;
    /**
     * Delete all parts in the geometry
     */
    deleteAllParts(): void;
}

/** @module cee.usg */ /** */
/**
 * An object describing the result of a picking action on an {@link UnstructGridModel}.
 *
 * Returned by {@link UnstructGridModel.rayIntersect}
 */
export interface HitItem {
    /**
     * The index of the state in which the geometry was hit
     */
    stateIndex: number;
    /**
     * The index of the part that was hit
     */
    partIndex: number;
    /**
     * The name of the part that was hit
     */
    partName: string;
    /**
     * The id of the element that was hit.
     */
    elementId: number;
    /**
     * The index of the element that was hit
     */
    elementIndex: number;
    /**
     * The number of nodes in the element that was hit
     */
    elementNodeCount: number;
    /**
     * The id of the closest node in the element that was hit.
     */
    closestNodeId: number;
    /**
     * The index of the closest node in the element that was hit
     */
    closestNodeIndex: number;
    /**
     * The position of the closest node in the element that was hit
     */
    closestNodePosition: Vec3;
    /**
     * The 3d point (in world coordinates) on the surface that was hit.
     *
     * This is the actual point that was hit
     */
    intersectionPoint: Vec3;
    /**
     * The normal of the surface at the point where the surface was hit.
     */
    intersectionPointNormal: Vec3;
}

/** @module cee.usg */ /** */
/**
 * Options to creating a mesh
 */
export interface OptionalMeshData {
    /**
     * If set to true, we will not preserve sharp edges (default false). Setting it to true is faster, but only usable for models without sharp edges or that have
     * already been split based on face crease angles.
     */
    noPreserveSharpEdges?: boolean;
    /**
     * Optional array with one Id for each node in the mesh
     */
    nodeIdArray?: ArrayLike<number>;
    /**
     * Optional array with one Id for each element in the mesh
     */
    elementIdArray?: ArrayLike<number>;
}
/**
 * A mesh defines the surface elements and nodes for a {@link Part} in a {@link Geometry}.
 *
 * A mesh is defined by a node array with x,y,z values and the element nodes describing the index of
 * the nodes in each element. The number of nodes per element is defined by either a singleElementType
 * for meshes where all the elements have the same number of nodes or by an array (elementTypeArr) with
 * one item per element describing the number of nodes in that element.
 *
 * Mesh is an immutable class, so if you need to change something you will have to construct a new mesh.
 */
export class Mesh {
    /**
     * Create a mesh.
     *
     * For mesh with only one element type (all elements have the same number of element nodes) use the singleElementType version. This is more
     * compact for storage.
     *
     * The nodeArr is an array of all the nodes in the mesh as an array with [x0, y0, z0, x1, y1, z1, ...].
     *
     * If you have a varying number of element nodes in your elements, specify that with an array
     * (elementTypeArr) with one item per element specifying the number of nodes for that element.
     *
    */
    constructor(nodeArr: ArrayLike<number>, singleElementType: number, elementNodeIndexArr: ArrayLike<number>, optionalData?: OptionalMeshData);
    constructor(nodeArr: ArrayLike<number>, elementTypeArr: ArrayLike<number>, elementNodeIndexArr: ArrayLike<number>, optionalData?: OptionalMeshData);
    /**
     * The number of nodes in the mesh.
     */
    get nodeCount(): number;
    /**
     * A readonly array containing the nodes of the mesh
     */
    get nodeArray(): ArrayLike<number>;
    /**
     * The number of elements in the mesh.
     */
    get elementCount(): number;
    /**
     * Returns an array containing the node indices for each element node in the mesh.
     */
    get elementNodeIndexArray(): ArrayLike<number>;
    /**
     * Returns the number of nodes in each element if all elements in the mesh have the same number of nodes
     *
     * Returns 0 if there are multiple element types.
     */
    get singleElementType(): number;
    /**
     * If not single element type, this array contains the number of elements for all elements in the mesh
     */
    get elementTypeArray(): ArrayLike<number> | null;
    /**
     * Returns the {@link BoundingBox} of the mesh.
     */
    getBoundingBox(): BoundingBox;
}

/** @module cee.usg */ /** */
/**
 * Class for querying the FEA mesh in an UnstructGridModel.
 *
 * You can use this class to both interrogate a mesh in its local coordinates and to query
 * a state in the model. If a state is specified the returned data will be in global coordinates,
 * taking any displacement and transformation result into account.
 */
export class MeshQuery {
    /**
     * Create the query object.
     *
     * If a mesh is specified, the query will be based on the mesh elements and nodes. The coordinate system
     * of the returned data will be in mesh local coordinates.
     *
     * If a state and part index is specified, the results (displacement and transformations) will be applied
     * if in use. So, in this case the coordinate system of the returned data will be in global coordinates.
     */
    constructor(mesh: Mesh);
    constructor(state: State, partIndex: number);
    /**
     * Returns an array containing the node indices for each element node in the given element
     */
    getElementNodeIndices(elementIndex: number): ArrayLike<number>;
    /**
     * Returns the position of the given node in the given part in this state.
     *
     * If a mesh is specified in the constructor, the coordinate system of the returned data will be in mesh local coordinates.
     * If a state and part index is specified in the constructor, the coordinate system of the returned data will be in global coordinates.
    */
    getNodePosition(nodeIndex: number): Vec3;
    /**
     * Returns the centroid of the given element
     *
     * If a mesh is specified in the constructor, the coordinate system of the returned data will be in mesh local coordinates.
     * If a state and part index is specified in the constructor, the coordinate system of the returned data will be in global coordinates.
    */
    getElementCentroid(elementIndex: number): Vec3;
    /**
     * Returns the surface normal of the given element
     *
     * If a mesh is specified in the constructor, the coordinate system of the returned data will be in mesh local coordinates.
     * If a state and part index is specified in the constructor, the coordinate system of the returned data will be in global coordinates.
    */
    getElementSurfaceNormal(elementIndex: number): Vec3 | null;
}

/** @module cee.usg */ /** */
/**
 * A part describes the elements and nodes in one part of the {@link Geometry}.
 *
 * A part links a mesh defining the part geometry (mesh) with the settings for the part. Parts can
 * share a mesh, and then e.g. use a transformation result to offset the parts.
 *
 * The part settings allows you to control the color, draw style, visibility and result settings
 * for the part.
 *
 * A part can have a user defined name and a customData property is provided to store any
 * application specific data for each part.
 */
export class Part {
    /**
     *
    */
    private constructor();
    /**
     * The name of the part
    */
    get name(): string;
    set name(name: string);
    /**
     * The mesh defining the elements and nodes of the part.
    */
    get mesh(): Mesh | null;
    set mesh(mesh: Mesh);
    /**
     * Returns an active reference to the settings for this part.
     */
    get settings(): PartSettings;
    /**
     * Custom data for the part. This field is not used by EnvisionWeb.
     */
    get customData(): any;
    /**
     *
     */
    set customData(data: any);
}

/** @module cee.usg */ /** */
/**
 * Displacement result for one part.
 *
 * The values stored are displacements or offsets to the geometry part nodes.
 *
 * The PartDisplacements class is immutable.
 */
export class PartDisplacements {
    /**
     * Create a displacement result for one part/mesh
     *
     * The array must contain x,y,z values for each node in the mesh, and have the length of 3*mesh.nodeCount
     *
     * Note that the displacementsArr should contain displacements relative to the mesh node, and not
     * new node coordinates.
     */
    constructor(displacementsArr: ArrayLike<number>);
    /**
     * The readonly array containing the displacements defined in this object
     */
    get displacementArray(): ArrayLike<number>;
}

/** @module cee.usg */ /** */
/**
 * Scalar results for one part in one state.
 *
 * The results can be mapped to the mesh as per node, per elements or per element node results.
 *
 * The PartScalars class is immutable.
 */
export class PartScalars {
    /**
     * Create a scalar result for a part/mesh with the given mapping and values.
     *
     * Note: There is some performance penalty for visualizing per element or per element node results,
     * as the vertices needs to be duplicated in order to produce the WebGL based visualization. This
     * will result in higher GPU and CPU memory usage.
     */
    constructor(resultMapping: ResultMapping, valueArray: ArrayLike<number>);
    /**
     * A readonly array with the scalar results
     */
    get valueArray(): ArrayLike<number>;
    /**
     * The result mapping of this object
     */
    get resultMapping(): ResultMapping;
    /**
     * The range (min/max) if the {@link valueArray}
     */
    getValueRange(): Range;
}

/** @module cee.usg */ /** */
/**
 * Part draw style. Specifies how parts should be rendered.
 */
export enum DrawStyle {
    /**
     * Render the part as surface.
     */
    SURFACE = 0,
    /**
     * Render the part as surface with an overlay of the element mesh. Note that this is not the triangle mesh,
     * but the actual FEA element mesh.
     */
    SURFACE_MESH = 1,
    /**
     * Render the part as surface with mesh lines on the feature edges (edges where the angle between two elements
     * are larger that 60 degrees).
     */
    SURFACE_OUTLINE_MESH = 2,
    /**
     * Render the edges of the elements as lines. Note that this is not the triangle edges but the FEA element edges.
     */
    LINES = 3,
    /**
     * Render the nodes of the part as points.
     */
    POINTS = 4,
    /**
     * Render the part as outline. Lines will be drawn on the feature edges (edges where the angle between two elements
     * are larger that 60 degrees).
     */
    OUTLINE = 5,
    /**
     * Render the part as lines, but use the depth buffer to remove lines that are obscured by the model itself.
     */
    HIDDEN_LINES_REMOVED = 6
}
/**
 * Settings describing how to render a {@link Part} in a {@link Geometry}.
 */
export class PartSettings {
    /**
     *
     */
    private constructor();
    /**
     * The visibility of the part
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * Whether the part should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
    /**
     * Flag controlling the shading model of the part.
     *
     * If true, smooth shading will be used for the part, where it is rendered with a smoothed out surface with
     * a per pixel lighting. If false, a flat shading rendering will be applied where the surface of an element
     * is rendered with the same color.
     *
     * Note: Flat shading requires each element to have unique vertices, so it will be slower and use more
     * memory (both normal and GPU).
     */
    get smooth(): boolean;
    /**
     *
     *
     */
    set smooth(smooth: boolean);
    /**
     * The specification of how to render the part
     */
    get drawStyle(): DrawStyle;
    set drawStyle(drawStyle: DrawStyle);
    /**
     * The color of the part. Note that the returned color cannot be modified.
     */
    get color(): Color3Like;
    set color(color: Color3Like);
    /**
     * The opacity of the part.
     *
     * 1.0 is fully opaque, 0.0 is fully transparent (invisible).
     */
    get opacity(): number;
    set opacity(opacity: number);
    /**
     * If true (default), scalar fringes will be shown on the part if present in the state. If false, no scalar will
     * be shown even if the result is present.
     */
    get fringesVisible(): boolean;
    set fringesVisible(visible: boolean);
    /**
     * If true (default), vector results will be shown on the part if present in the state. If false, no vector result will
     * be shown even if the result is present.
     */
    get vectorsVisible(): boolean;
    set vectorsVisible(visible: boolean);
    /**
     * If true (default), displacements will be used (if present) for the part
     */
    get displacementVisible(): boolean;
    set displacementVisible(visible: boolean);
}

/** @module cee.usg */ /** */
/**
 * Vector result for one part.
 *
 * The vector result is a 3d result (x,y,z) for each result position in part. Per node, per element and
 * per element node mapping is supported.
 *
 * The PartVectors class is immutable.
 */
export class PartVectors {
    /**
     * Create a vector result for one part/mesh
     *
     * The array must contain x,y,z values for each result.
     */
    constructor(resultMapping: ResultMapping, vectorsArr: ArrayLike<number>);
    /**
     * The readonly array containing the vector result defined in this object
     */
    get vectorArray(): ArrayLike<number>;
    /**
     * The result mapping of this vector result
     */
    get resultMapping(): ResultMapping;
    /**
     * The range (min/max) of the vector lengths in this result
     */
    getVectorLengthRange(): Range;
}

/** @module cee.usg */ /** */
/**
 * Setting for how a scalar should be shown in the model.
 *
 * You can get the settings for the scalar shown as fringes (filled contours) with the
 * {@link UnstructGridModel.fringesSettings} property.
 *
 * Example using the ScalarMapperFilledContoursUniform:
 * ```javascript
 // Configure the mapper to use, and
 const mapper = new cee.ScalarMapperFilledContoursUniform();
 mapper.colorArray = cee.ColorTableFactory.color4TableArray(cee.ColorTable.RAINBOW, 15);
 mapper.setRange(1,4);
 model.fringesSettings.scalarMapper = mapper;

 // Add a color legend based on the mapper
 this.m_view.overlay.addCustomColorLegendForScalarMapper(mapper, "Demo result", 1);
 * ```
 */
export class ScalarSettings {
    /**
     * The name of the scalar result
    */
    get name(): string;
    set name(name: string);
    /**
     * The scalar mapper to use to map from a scalar value to a color
     *
     * EnvisionWeb offers 4 different scalar mappers:
     *
     * - {@link cee.ScalarMapperFilledContours}
     * - {@link cee.ScalarMapperFilledContoursUniform}
     * - {@link cee.ScalarMapperContinuous}
     * - {@link cee.ScalarMapperContinuousPiecewise}
     *
     * To add a color legend to a view to show the scalar mapper, use the {@link cee.Overlay.addCustomColorLegendForScalarMapper}
     * method (see example above).
     */
    get scalarMapper(): ScalarMapperContinuousDomain | null;
    set scalarMapper(scalarMapper: ScalarMapperContinuousDomain);
}

/** @module cee.usg */ /** */
/**
 * A state connects a geometry to the results (scalar, vector, displacement and transformations) for a given
 * time, frequency, load case etc.
 *
 * A model can have an arbitrary number of states, but only one can be shown at any given time.
 *
 * To create an animation you can create multiple states, and then only change the
 * {@link UnstructGridModel.currentStateIndex} property to advance the animation.
 *
 * A state must have one and only one geometry.
 *
 * The state can also have a scalar, vector, displacement and transformation result.
 *
 * For the results, you only have to specify the results for the parts that have results. Results
 * are mapped to part via the zero based part index.
 */
export class State {
    /**
     *
    */
    private constructor();
    /**
     * The user defined name of the state
    */
    get name(): string;
    set name(name: string);
    /**
     * The user defined reference value of the state (time, frequency, load case index, etc)
    */
    get referenceValue(): number | undefined;
    set referenceValue(value: number | undefined);
    /**
     * The one and only geometry in this state
    */
    get geometry(): Geometry | null;
    set geometry(geometry: Geometry);
    /**
     * Set the scalar result that should be shown as fringes for the given part in this state.
     *
     * Note: The {@link PartSettings.fringesVisible} property must be true to show the result (default true)
    */
    setPartFringesAt(partIndex: number, partFringes: PartScalars | null): void;
    /**
     * Remove all scalar fringes results from this state
    */
    removeAllPartFringes(): void;
    /**
     * Returns the {@link PartScalars} defining the fringes result shown on the given part. Null when none is specified.
    */
    getPartFringesAt(partIndex: number): PartScalars | null;
    /**
     * Get the min/max value of the scalar result in this part.
    */
    getFringesResultRange(): Range;
    /**
     * Set the vector result that should be shown as vector arrows for the given part in this state.
     *
     * Note: The {@link PartSettings.vectorsVisible} property must be true to show the result (default true)
    */
    setPartVectorsAt(partIndex: number, partVectors: PartVectors | null): void;
    /**
     * Remove all vector results for all parts in this state
    */
    removeAllPartVectors(): void;
    /**
     * Returns the {@link PartVectors} defining the vector result shown on the given part. Null if not specified.
    */
    getPartVectorsAt(partIndex: number): PartVectors | null;
    /**
     * The range (min/max) of the vector lengths in all parts
    */
    getVectorLengthRange(): Range;
    /**
     * Set the displacement result for the given part in this state
     *
     * Note: The {@link PartSettings.displacementVisible} property must be true to show the result (default true)
    */
    setPartDisplacementsAt(partIndex: number, partDisplacements: PartDisplacements | null): void;
    /**
     * Remove all displacement results in this state
    */
    removeAllPartDisplacements(): void;
    /**
     * Get the displacement result at the given zero based index, otherwise null.
    */
    getPartDisplacementsAt(partIndex: number): PartDisplacements | null;
    /**
     * Set the transformation result (matrix) for the given part in this state.
    */
    setPartTransformationAt(partIndex: number, partTransformationMatrix: Mat4 | null): void;
    /**
     * Get the transformation matrix for the given part in this state, null if none is specified.
    */
    getPartTransformationAt(partIndex: number): Mat4 | null;
    /**
     * Remove the transformation matrices for all parts in this state
    */
    removeAllPartTransformations(): void;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the model.
     */
    getBoundingBox(): BoundingBox;
}

/** @module cee.usg */ /** */
/**
 * Available result mappings
 */
export enum ResultMapping {
    /**
     * One result per node in the part. Number of results: Mesh.nodeCount
     */
    PER_NODE = 0,
    /**
     * One result per element in the part. Number of results: Mesh.elementCount
     */
    PER_ELEMENT = 1,
    /**
     * One result per element node in the part. Number of results: Mesh.elementNodeIndexArray.length
     */
    PER_ELEMENT_NODE = 2
}
/**
 * The available memory usage strategies (both Javascript and GPU) for an UnstructGridModel
 */
export enum VizStateStrategy {
    /**
     * Only keep the visualization data and GPU buffers for the current state. Changing states will require a regeneration of the display model.
     *
     * This is the option with the smallest memory footprint (both GPU and main memory).
     */
    VIZ_STATES_SINGLE = 0,
    /**
     * Keep the visualization data for all states, but delete GPU buffer resources when changing state.
     *
     * This option will use more main memory, but still keeps GPU memory usage at the same level as what is needed for a single state.
     */
    VIZ_STATES_ALL_SINGLE_GPU = 1,
    /**
     * Keep everything needed for all states to be rendered as quickly as possible.
     *
     * This is the fastest way to play an animation, but requires sufficient resources (both main browser memory and GPU) to run.
     */
    VIZ_STATES_ALL = 2
}
/**
 * Options for the UnstructGridModel
 */
export interface UnstructGridModelOptions {
    /**
     * Strategy to use for multiple states (animation) in UnstructGridModel.
     *
     * This setting controls how much memory (both Javascript and GPU) is kept between states.
     * Use this setting to balance between rendering performance and resource usage.
     *
     * Default is VIZ_STATES_SINGLE (most conservative on memory usage).
     *
     * See {@link VizStateStrategy} for more information.
     */
    vizStateStrategy: VizStateStrategy;
}
/**
 * The UnstructGridModel implements a client side model for handling surface CAE models.
 *
 * It handles surface elements with any number of nodes. A model has one or more {@link State}s, which links a {@link Geometry} to
 * scalar, displacement and transformation results for that geometry in that state.
 *
 * Here is a simple example of how to create an usg model containing a single quad element
 * with a per node scalar result in one state:
 *
 * ```javascript
let model = new cee.usg.UnstructGridModel();
this.m_view.addModel(model);

let geometry = new cee.usg.Geometry();
let part = geometry.addPart();
 
// Create a single quad mesh
const nodeArr = [0,0,0, 1,0,0, 1,1,0, 0,1,0];
const elConnArr = [0,1,2,3];
part.mesh = new cee.usg.Mesh(nodeArr, 4, elConnArr);
 
// Configure the visual appearance of the part
part.settings.color = new cee.Color3(1,0,0);
part.settings.drawStyle = cee.usg.DrawStyle.SURFACE_MESH

// Create a state, set the geometry and add the scalar result
let state = model.addState();
state.geometry = geometry;

let scalarArr = [1,2,3,4];
state.setPartFringesAt(0, new cee.usg.PartScalars(cee.usg.ResultMapping.PER_NODE, scalarArr));

// Configure the mapper to use, and
const mapper = new cee.ScalarMapperFilledContoursUniform();
mapper.colorArray = cee.ColorTableFactory.color4TableArray(cee.ColorTable.RAINBOW, 15);
mapper.setRange(1,4);
model.fringesSettings.scalarMapper = mapper;

// Add a color legend based on the mapper
this.m_view.overlay.addCustomColorLegendForScalarMapper(mapper, "Demo result", 1);
 * ```
 * This code sample produces the following image in the 3D Viewer:
 *
 * ![](/images/UsgModel.png)
 */
export class UnstructGridModel extends Model {
    /**
     * Create the UnstructGridModel
     *
     * Use the options to set the resource usage strategy for the model in a multi-state scenario. See
     * {@link UnstructGridModelOptions} for more info.
     */
    constructor(options?: UnstructGridModelOptions);
    /**
     * The name of the geometry model. Mainly used for debugging.
     */
    get name(): string;
    set name(name: string);
    /**
     * Returns the number of states in this model
     */
    get stateCount(): number;
    /**
     * The state to show in the view.
     *
     * The given zero-based index must be between 0 and {@link stateCount} - 1.
     */
    get currentStateIndex(): number;
    set currentStateIndex(stateIndex: number);
    /**
     * The zero based index of the state currently shown in the view. Returns null for an invalid {@link currentStateIndex}.
     */
    get currentState(): State | null;
    /**
     * Settings for the scalars shown as fringes on the model
     */
    get fringesSettings(): ScalarSettings;
    /**
     * Settings for the scalars shown as fringes on the model
     */
    get vectorSettings(): VectorSettings;
    /**
     * Settings for the displacement results
     */
    get displacementSettings(): DisplacementSettings;
    /**
     * Returns a readonly array of all the states in the model
     */
    getStateArray(): ReadonlyArray<State>;
    /**
     * Add a state to the model.
     *
     * The added state is returned.
     */
    addState(): State;
    /**
     * Delete a state at the given zero based index.
     */
    deleteStateAt(stateIndex: number): void;
    /**
     * Delete a range of states. First state that will be deleted is the state with the given index
     * If deleteCount is omitted, all states starting with the given index will be deleted.
     *
     * Works similar to the splice method on Javascript arrays
     */
    deleteStateRange(startIndex: number, deleteCount?: number): void;
    /**
     * Delete all states in the model.
     */
    deleteAllStates(): void;
    /**
     * Returns a reference to the state at the given index
     */
    getStateAt(stateIndex: number): State;
    /**
     * Get the range of the scalar result in this model
    */
    getFringesResultRange(): Range;
    /**
     * Performs picking on the model in the current state.
     *
     * If something was hit, returns a HitItem containing information about the part and primitive that was hit.
     *
     * If nothing was hit, returns null.
     */
    rayIntersect(ray: Ray): HitItem | null;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the current state within the model.
     *
     * The returned bounding box will reflect the currently visible objects in the model.
     *
     * Note that this method does not support any {@link ModelBoundingBoxOptions}
     */
    getBoundingBox(_options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns default camera configuration, which is always null for this model.
     */
    getDefaultCameraConfig(): null;
}

/** @module cee.usg */ /** */
/**
 * Scaling mode for vector results
 */
export enum ScaleMode {
    /**
     * Absolute scaling of vectors. The vector is multiplied with the scaleFactor before being drawn.
     */
    ABSOLUTE_SCALING = 0,
    /**
     * Scales vectors relative to model extent. The scaleFactor is considered to be a fraction of the
     * model extent. So a value of 0.2 (default) will make the longest vector 20% of the model extent.
     */
    RELATIVE_SCALING = 1
}
/**
 * Setting for how a vector result should be shown in the model.
 *
 * You can get the vector settings with the {@link UnstructGridModel.vectorSettings} property.
 *
 */
export class VectorSettings {
    /**
     * The name of the vector result
    */
    get name(): string;
    set name(name: string);
    /**
     * The color of the vector arrows
    */
    get singleVectorColor(): Color3;
    set singleVectorColor(color: Color3);
    /**
     * Scaling factor to use on the vector result
    */
    get scaleFactor(): number;
    /**
     * Scaling mode (absolute or relative) to use use for the vector result
     *
     * If set to ABSOLUTE_SCALING, the vector result will be multiplied by the scaling factor.
     *
     * If set to RELATIVE_SCALING, the scaling factor is assumed to be a fraction of the extent of the model
     * bounding box, making the longest vector: boundingBox.extent().length()*scaleFactor
    */
    get scaleMode(): ScaleMode;
    /**
     * The radius of the vector arrow shaft relative to the vector length.
     */
    get arrowShaftRelativeRadius(): number;
    set arrowShaftRelativeRadius(shaftRelativeRadius: number);
    /**
     * The radius of the vector arrow head relative to the vector length.
     */
    get arrowHeadRelativeRadius(): number;
    set arrowHeadRelativeRadius(headRelativeRadius: number);
    /**
     * The length of the vector arrow head relative to the vector length.
     */
    get arrowHeadRelativeLength(): number;
    set arrowHeadRelativeLength(headRelativeLength: number);
    /**
     * Set the scaling factor and scaling mode to use on the vector result
     *
     * If mode is ABSOLUTE_SCALING, the vector result will be multiplied by the scaleFactor.
     *
     * If mode is RELATIVE_SCALING, the scaleFactor is assumed to be a fraction of the extent of the model
     * bounding box, making the longest vector: boundingBox.extent().length()*scaleFactor
    */
    setScaleFactor(mode: ScaleMode, scaleFactor: number): void;
}

} // usg



//
// utils
// ===================================================================================
export namespace utils {

/** @module cee.utils */ /** */
export abstract class AbstractSolidGenerator {
    /**
     * The generate method generates the object by filling `m_vertices` and `m_indices`.
     */
    abstract generate(): void;
    /**
     * Get the vertices of the solid object as Vec3
     */
    getVertices(): Vec3[];
    /**
     * Get the vertices of the solid object as a number array with <x,y,z,x,y,z,...>
     */
    getVerticesNumber(): number[];
    /**
     * Get the indices of triangles needed to render the solid object
     */
    getIndices(): number[];
    /**
     * Fills the members `m_vertices` and `m_indices` of this class.
     * @param vertices The vertices in the format x,y,z,x,y,z,...
     * @param indices The indices for the vertices
     */
    protected fillVerticesIndices(vertices: Float32Array, indices: number[]): void;
}

/**
 * The arrow generator configuration object, see {@link ArrowGenerator}.
 */
export interface ArrowGeneratorConfig {
    /**
     * The relative radius of the arrow's shaft to the arrow's length of 1.
     */
    shaftRelativeRadius?: number;
    /**
     * The relative radius of the arrow's head to the arrow's length of 1.
     */
    headRelativeRadius?: number;
    /**
     * The relative length of the arrow's head compared to the arrow's body (the total length is 1).
     * A value of 0.2 will result in a body that is 0.8 in length.
     */
    headRelativeLength?: number;
    /**
     * The number of slices for both the head and the shaft of the arrow. Minimum is 4.
     */
    numSlices?: number;
}
/**
 * Helper class to tesselate an arrow
 */
export class ArrowGenerator extends AbstractSolidGenerator {
    /**
     *
     */
    constructor();
    /**
     * Specify the arrow by providing its relative proportions.
     */
    configure(config: ArrowGeneratorConfig): void;
    /**
     * Generate the arrow
     */
    generate(): void;
    /**
     * Generate the reverse arrow, with the arrow head pointing into the origin.
     */
    generateReverse(): void;
}

/** @module cee.utils */ /** */
/**
 * Helper class to tesselate a box with 6 faces
 *
 * Useful when result values need to be mapped onto a set of 3D points defining a box.
 * See the method `createCuttingSolid` in the example in Examples/DemoAppUg on how to do that.
 */
export class BoxGenerator extends AbstractSolidGenerator {
    /**
     *
     */
    constructor();
    /**
     * Specify the box by providing an origin (min x,y,z of the box) and the extent in x,y and z direction.
     */
    setOriginAndExtent(origin: Vec3, extent: Vec3): void;
    /**
     * Specify the box by providing the center of the box and the extent in x,y, and z direction.
     */
    setCenterAndExtent(center: Vec3, extent: Vec3): void;
    /**
     * Set the orientation of the box by giing the right direction (local x axis) and the up direction
     * (local z axis).
     */
    setOrientation(rightDir: Vec3, upDir: Vec3): void;
    /**
     * Sets the number of segments of the box per axis.
     */
    setNumSegments(numX: number, numY: number, numZ: number): void;
    /**
     * Generate the box
     */
    generate(): void;
}

/** @module cee.utils */ /** */
/**
 * Helper class to tesselate a cone
 */
export class ConeGenerator extends AbstractSolidGenerator {
    /**
     *
     */
    constructor();
    /**
     * Specify the cone by giving origin (center of bottom circle) and the bottom radius + height
     */
    setOriginAndSize(origin: Vec3, bottomRadius: number, height: number): void;
    /**
     * Generate the cone
     */
    generate(): void;
}

/** @module cee.utils */ /** */
/**
 * The cylinder generator configuration object, see {@link CylinderGenerator}.
 */
export interface CylinderGeneratorConfig {
    /**
     * The origin point of the cylinder, which is the bottom center point.
     */
    origin?: Vec3;
    /**
     * The symetric, longitudinal axis of the cylinder. It will grow from the `origin` in this direction.
     */
    direction?: Vec3;
    /**
     * The radius of the cylinder.
     */
    radius?: number;
    /**
     * Cylinder's height along the `direction`.
     */
    height?: number;
    /**
     * Number of 'cake slices' going trough both caps and the walls of the cylinder.
     */
    numSlices?: number;
    /**
     * Number of segments along the `direction` of the cylinder, in other words slices which are parallel to the caps.
     */
    numSegmentsZdirection?: number;
    /**
     * Number of concentric 'tree rings' segments in both caps of the cylinder.
     */
    numConcentricSegmentsInCaps?: number;
}
/**
 * Helper class to tesselate a cylinder with closed caps.
 *
 * Useful when result values need to be mapped onto a set of 3D points defining a cylinder.
 * See the method `createCuttingSolid` in the example in Examples/DemoAppUg on how to do that.
 */
export class CylinderGenerator extends AbstractSolidGenerator {
    /**
     *
     */
    constructor();
    /**
     * Sets up the cylinder parameters.
     */
    configure(config: CylinderGeneratorConfig): void;
    /**
     * Generates the cylinder, using the previously provided configuration.
     */
    generate(): void;
}

export class ManipulatorTrackball {
    constructor();
    /**
     * Returns the primary navigation type used by the trackball manipulator.
     */
    getPrimaryNavigationType(): NavigationType;
    /**
     * The camera tracked by the trackball manipulator.
     */
    getCamera(): Camera;
    /**
     * The rotation point used by the trackball manipulator
     */
    setRotationPoint(rotPoint: Vec3): void;
    /**
     * The rotation axis used by the trackball manipulator. Set null to not constrain the rotation
     * to a specific axis.
     */
    setRotationAxis(rotAxis: Vec3 | null): void;
    /**
     * Invert the zoom and walk direction
     */
    setInvertZoomAndWalk(invert: boolean): void;
    /**
     * Controls the sensitivity of the rotation operation.
     */
    setRotationSensitivity(sensitivity: number): void;
    /**
     * Begins the specified navigation type using the provided initial X/Y screen point
     */
    startNavigation(navigationType: NavigationType, x: number, y: number): void;
    /**
     * Ends and stops tracking the current navigation operation
     */
    endNavigation(): void;
    /**
     * Updates the current primary navigation operation with the new provided X/Y screen point compared
     * to the previously provided X/Y screen point.
     */
    updateNavigation(x: number, y: number): boolean;
    /**
     * Provides the current state of the view camera to the trackball manipulator camera.
     * This is used as a reference position to calculate the relative translation of the view camera.
     */
    updateTrackballCamera(viewCamera: Camera): void;
    /**
     * Returns the relative translation of the view camera since the last updateTrackballCamera() call.
     */
    deltaMatrix(): Mat4;
    /**
     * Sets the minimum distance the camera can be from the target point when walking.
     */
    setMinWalkTargetDistance(distance: number): void;
    /**
     * Controls the sensitivity of the walk operation.
     */
    setWalkSensitivity(sensitivity: number): void;
}

/**
 * Helper class to generate vertices for paths
 */
export class PathGenerator {
    /**
     * Generates vertices to draw a path connecting the given points
     */
    static generateVerticesForPath(points: Vec3[]): number[];
    /**
     * Generates vertices to draw a circle.
     */
    static generateVerticesForCircle(center: Vec3, normal: Vec3, radius: number, numSegments: number): number[];
    /**
     * Generates vertices to draw a circle passing through the given 3 points.
     * Returns null when the points (p1, p2, p3) do not specify a circle, e.g. they lie on a straight line.
     */
    static generateVerticesForCircleThrough3Points(p1: Vec3, p2: Vec3, p3: Vec3, numSegments: number): number[] | null;
    /**
     * Generates vertices to draw a circular segment between the lines <center, endPoint1> and <center, endPoint2>.
     * Returns null when the points (center, endpoint1, endpoint2) do not specify a circle, e.g. they lie on a straight line.
     */
    static generateVerticesForCircularSegmentBetween2Lines(center: Vec3, endPoint1: Vec3, endPoint2: Vec3, radius: number, numSegments: number): number[] | null;
}

/** @module cee.utils */ /** */
/**
 * The sphere generator configuration object, see {@link SphereGenerator}.
 */
export interface SphereGeneratorConfig {
    /**
     * The center point of the sphere.
     */
    center: Vec3;
    /**
     * The radius point of the sphere.
     */
    radius: number;
    /**
     * Number of slices from which the sphere will be generated. Used for both angles (directions) on the sphere.
     */
    numSlices: number;
}
/**
 * Helper class to tesselate a sphere
 *
 * Useful when result values need to be mapped onto a set of 3D points defining a sphere.
 * See the method `createCuttingSolid` in the example in Examples/DemoAppUg on how to do that.
 */
export class SphereGenerator extends AbstractSolidGenerator {
    /**
     *
     */
    constructor();
    /**
     * Sets up the sphere parameters.
     */
    configure(config: SphereGeneratorConfig): void;
    /**
     * Generates the sphere, using the previously provided configuration.
     */
    generate(): void;
}

} // utils



//
// cug
// ===================================================================================
export namespace cug {

/** @module cee.cug */ /** */
export interface Animation {
    /**
     * The target animation speed in frames per second (fps).
     *
     * This will be the maximum animation speed, but the actual speed may be lower for large
     * models or slow clients.
     */
    targetFrameRate: number;
    /**
     * The number of steps to use for the particle trace animation.
     *
     * The number of steps will be used to calculate the delta time for each step in the animation
     * based on the total time of all active traces.
     */
    particleTraceAnimationStepCount: number;
    /**
     * Starts or stops an animation
     */
    runAnimation(run: boolean): void;
    /**
     * Starts or stops a particle trace animation.
     */
    runParticleTraceAnimation(run: boolean): void;
    /**
     *
     */
    setFirstFrame(): void;
    /**
     *
     */
    setLastFrame(): void;
    /**
     *
     */
    setNextFrame(): void;
    /**
     *
     */
    setPreviousFrame(): void;
}

/** @module cee.cug */ /** */
/**
 *  BinaryModelBundle
 */
export class BinaryModelBundle {
    /**
     *
     */
    constructor();
    /**
     *
     */
    static fromArrayBuffer(bundleArrayBuffer: ArrayBuffer): BinaryModelBundle;
    /**
     *
     */
    static fromBase64ModelBundle(base64ModelBundle: Base64ModelBundle): BinaryModelBundle;
}

/** @module cee.cug */ /** */
/**
 *  Base64ModelBundle
 */
export interface Base64ModelBundle {
    /**
     * Magic string including bundle version number, eg "cugbundle_ver00"
     */
    bundleMagic: string;
    /**
     * Model info in the shape of a CUGSModelInfo object
     */
    modelInfo: any;
    /**
     * Array of base64 encoded frames, indexed by frame index
     */
    frameArr: string[];
    /**
     * Array of base64 encoded fragments, indexed by fragment index
     */
    fragmentArr: string[];
}

/** @module cee.cug */ /** */
export interface InitializationCompleteInfo {
    boundingBox: BoundingBox;
    defaultCamera?: CameraConfig;
}
export interface InitializationCompleteCallback {
    (error: Error | null, info: InitializationCompleteInfo): void;
}
/**
 * A callback that will be called when the streaming of the ConstantRemoteModel is complete, that is the client has all the information needed
 * to render the model in full resolution.
 *
 * You can register to receive a callback with the {@link ConstantRemoteModel.setOneShotDataStreamingCompleteCallback} method.
 */
export interface DataStreamingCompleteCallback {
    (model: ConstantRemoteModel): void;
}
/**
 * Interface describing progress data. Used in {@link ProgressHandler}
 */
export interface ProgressData {
    /**
     * The completion percentage of current streaming operation (0..100)
     */
    pctDone: number;
    /**
     * Message useful for debugging.
     */
    debugMessage: string;
}
/**
 * Progress event handler function that will be called whenever there is new progress data
 */
export interface ProgressHandler {
    (progressData: ProgressData): void;
}
/**
 * A callback function invoked when the result of a {@link ConstantRemoteModel.rayIntersect} call is ready.
 *
 * The parameter provided to this function contains a {@link HitItem} which provides server-side information
 * about the hit on the constant remote model.
 */
export interface RayIntersectCallback {
    (hitItem: HitItem | null): void;
}
/**
 * Options for ConstantRemoteModel.openModel()
 *
 * customFetchRequestInit: Contains custom settings that will be applied to the fetch requests, see
 * documentation for https://developer.mozilla.org/en-US/docs/Web/API/WindowOrWorkerGlobalScope/fetch
 */
export interface OpenModelOptions {
    customFetchRequestInit?: RequestInit;
    internal_packetCaptureDestination?: BinaryModelBundle;
}
/**
 * Options for ConstantRemoteModel.openRemoteBundle()
 *
 * customFetchRequestInit: Contains custom settings that will be applied to the fetch requests, see
 * documentation for https://developer.mozilla.org/en-US/docs/Web/API/WindowOrWorkerGlobalScope/fetch
 */
export interface OpenRemoteBundleOptions {
    customFetchRequestInit?: RequestInit;
}
/**
 * A constant remote model designed for viewing CAE models with a stateless, scalable server.
 *
 * The ConstantRemoteModel supports an efficient and scalable streaming of pre-defined CAE model configurations.
 * The server is a stateless REST API based server that has very low resource usage on the server side and is easy to load balance.
 * The streaming also starts immediately when a model is opened, no matter the size of the model.
 * Similar to RemoteModel, it utilizes 3D Progressive Object Streaming to the client. The model needs to be converted
 * into a CUG database format before it can be streamed. This is done with the included CugComposer command line utility.
 *
 * The ConstantRemoteModel is used in the viewer on Ceetron Cloud.
 *
 * See the example in Examples/BuildYourFirstApp/2-Viewer for how to use the ConstantRemoteModel.
 */
export class ConstantRemoteModel extends Model implements ProcessableModel {
    /**
     * Creates a ConstantRemoteModel.
     */
    constructor();
    /**
     * Name of the model.
     *
     * Mainly used for debugging.
     */
    get name(): string;
    set name(name: string);
    /**
     * Returns the SimulationInfo describing the simulation that is the source for this model.
     *
     * Might return null if model is not streamed yet or the model does not have simulation info
     */
    get simulationInfo(): SimulationInfo | null;
    /**
     * Returns the ModelSpec describing the result used in this model
     *
     * Might return null if model is not streamed yet or the model does not have result info.
     */
    get modelSpec(): ModelSpec | null;
    /**
     * Returns the number of parts in this model
     */
    get partCount(): number;
    /**
     *
     */
    get cuttingPlaneCount(): number;
    /**
     *
     */
    get isosurfaceCount(): number;
    /**
     *
     */
    get isovolumeCount(): number;
    /**
     *
     */
    get particleTraceGroup(): number;
    /**
     *
     */
    get frameCount(): number;
    /**
     * The frame to show
     *
     * The given zero-based index must be between 0 and {@link frameCount} - 1.
     */
    get currentFrameIndex(): number;
    set currentFrameIndex(frameIndex: number);
    /**
     * The animation control for this ConstantRemoteModel
     */
    get animation(): Animation | null;
    /**
     * The color of the element mesh on the surface of the part
     */
    get meshColor(): Color3Like;
    set meshColor(color: Color3Like);
    /**
     * Set a master model to which animation in this model will be synchronized.
     *
     * Calling this function will make this model a slave of masterModel with regards to animations.
     * This means that animations will be controlled via the master model's animation control and that
     * this model's animation control become invalid.
     * To set this model back to normal operation, pass null to this function.
     */
    setMasterModelForSyncAnimation(masterModel: ConstantRemoteModel | null): void;
    /**
     *
     */
    setCurrentParticleTraceTime(time: number, isFirstParticleTraceCycle: boolean): void;
    /**
     *
     */
    getCurrentParticleTraceTime(): number;
    /**
     *
     */
    isFirstParticleTraceCycle(): boolean;
    /**
     *
     */
    enablePreLoading(enable: boolean): void;
    /**
     *
     */
    setGuidingCamera(camera: Camera): void;
    /**
     * Sets a handler function that will be called whenever when new progress data is available
     */
    setProgressHandler(progressHandler: ProgressHandler): void;
    /**
     *
     */
    openModel(serverUrl: string, modelKey: string, options?: OpenModelOptions, initializationCompleteCallback?: InitializationCompleteCallback): void;
    /**
     *
     */
    openRemoteBundle(bundleUrl: string, options?: OpenRemoteBundleOptions, initializationCompleteCallback?: InitializationCompleteCallback): void;
    /**
     *
     */
    openLocalBundle(modelBundle: BinaryModelBundle, initializationCompleteCallback?: InitializationCompleteCallback): void;
    /**
     * Sets a one- shot callback that will be called the next time we observe that data streaming is complete
     */
    setOneShotDataStreamingCompleteCallback(dataStreamingCompleteCallback: DataStreamingCompleteCallback): void;
    /**
     *
     */
    closeModel(): void;
    /**
     *
     */
    getFrameInfoArray(): ReadonlyArray<FrameInfo>;
    /**
     *
     */
    getFrameInfoAt(index: number): FrameInfo;
    /**
     * Get the array with all ResultInfos defined in this model
     */
    getResultInfoArray(): ReadonlyArray<ResultInfo>;
    /**
     * Get the information about the result with the given type and id.
     *
     * Returns null if the result was not found.
     */
    getResultInfo(resultType: ResultType, resultId: number): ResultInfo | null;
    /**
     *
     */
    getPartArray(): ReadonlyArray<Part>;
    /**
     *
     */
    getPartAt(index: number): Part;
    /**
     *
     */
    getCuttingPlaneArray(): ReadonlyArray<CuttingPlane>;
    /**
     *
     */
    getCuttingPlaneAt(index: number): CuttingPlane;
    /**
     *
     */
    getIsosurfaceArray(): ReadonlyArray<Isosurface>;
    /**
     *
     */
    getIsosurfaceAt(index: number): Isosurface;
    /**
     *
     */
    getIsovolumeArray(): ReadonlyArray<Isovolume>;
    /**
     *
     */
    getIsovolumeAt(index: number): Isovolume;
    /**
     *
     */
    getParticleTraceGroupArray(): ReadonlyArray<ParticleTraceGroup>;
    /**
     *
     */
    getParticleTraceGroupAt(index: number): ParticleTraceGroup;
    /**
     * Performs picking on the model using the current frame.
     *
     * If something was hit, returns a HitItem containing information about the object that was hit.
     * Returns null if nothing was hit.
     */
    rayIntersect(ray: Ray): HitItem | null;
    /**
     * Set the title of the color legend with the given result Id
     *
     * This will update any current legends, and also be used as the title whenever the legend is later
     * created.
     */
    setColorLegendTitle(resultId: number, title: string): void;
    /**
     * Performs picking on the model using the current frame, querying the server for additional info
     *
     * If something was hit, returns a HitItem containing information about the object that was hit.
     * Returns null if nothing was hit.
     *
     * This method will query the CUG server for additional info on the selected item
     */
    rayIntersectServerInfo(ray: Ray, rayIntersectCallback: RayIntersectCallback): void;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the current contents of the model
     *
     * Note that currently this method does not support any {@link ModelBoundingBoxOptions}
     */
    getBoundingBox(_options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the part at the given index.
     */
    getBoundingBoxForPart(partIndex: number): BoundingBox;
    /**
     * Returns default camera configuration for this model if there is one.
     */
    getDefaultCameraConfig(): CameraConfig | null;
}

/**
 * The **cug** sub-module provides a constant remote model designed for viewing CAE models.
 *
 * the cug module may be referenced using the `cee.cug` prefix, e.g.:
 *
 * ```javascript
 * var model = new cee.cug.ConstantRemoteModel();
 * ```
 *
 * **Features**
 *
 *  * Scalable CAE Model visualization in the Cloud
 *  * Starts streaming immediately, independent of model size
 *  * State-less, RESTful API based server
 *  * No native add-on for server, no web sockets
 *  * Easy to scale, low cost to deploy
 *  * The viewer in Ceetron Cloud 2.0
 *
 * **Supports interactive viewing of all cee.ug features**
 *
 *  * Model with scalars, vectors and displacements
 *  * All part attributes (mesh, draw style, transparency, etc)
 *  * Time, mode-shape and particle trace animations
 *  * Cutting planes, isosurfaces, isovolumes
 *  * Particle traces
 *
 * **Interactive features**
 *
 *  * Pan/rotate/zoom
 *  * Show/hide model mesh
 *  * Show/hide parts and objects
 *  * Animation control
 *
 * **Server**
 *
 * The ConstantRemoteModel requires the use of a server (CugServer). Models needs to be converted into a CUG database format before they can be streamed.
 * The conversion is done with the CugComposer command line application which is provided in the NativeApplications/CugComposer/bin/<PLATFORM> folder of the
 * distribution (binaries for Windows, Linux and MacOS).
 *
 * The CUG server uses a DataStore interface to access data, and ships with a FileDataStore. It can be extended to pull data from other sources.
 *
 * @module cee.cug
 *
 */ /** */

/**
 *
 */
export class CuttingPlane {
    /**
     *
    */
    private constructor();
    /**
     * The result id of the scalar result mapped on the cutting plane.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapScalarResultId(): number;
    /**
     * The result id of the vector result mapped on the cutting plane.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapVectorResultId(): number;
    /**
     * The result id of the scalar result shown as contour lines on the cutting plane.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapContourLinesResultId(): number;
    /**
     *
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * Whether the cutting plane should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
}

/**
 *  Information about each frame in the ConstantRemoteModel
 */
export class FrameInfo {
    /**
     * The state id of the current frame
     */
    get stateId(): number;
    /**
     * The name of the current frame
     */
    get name(): string;
    /**
     * The reference value of the current frame
     *
     * The reference value is provided by the CAE reader/data provider and is simulation specific.
     */
    get referenceValue(): number | undefined;
    /**
     * Minimum value of the scalar result shown as fringes on the model in this frame
     */
    get fringesMinimumValue(): number | undefined;
    /**
     * Maximum value of the scalar result shown as fringes on the model in this frame
     */
    get fringesMaximumValue(): number | undefined;
}

/** @module cee.cug */ /** */
/**
 * An object describing the result of a picking action on a {@link ConstantRemoteModel}.
 *
 * Returned by {@link ConstantRemoteModel.rayIntersect}
 */
export interface HitItem {
    /**
     * The index of the frame in which the picking occurred
     */
    frameIndex: number;
    /**
     * The type of object (part/iso/cut/isovol) that was hit
     */
    objectType: ObjectType;
    /**
     * The index of the object (part/iso/cut/isovol) that was hit
     */
    objectIndex: number;
    /**
     * The id of the node in the data model on the server that was hit
     */
    nodeId: number;
    /**
     * The index of the node in the data model on the server that was hit
     */
    nodeIndex: number;
    /**
    * The position of the node in the data model on the server that was hit
    */
    nodePosition: Vec3 | null;
    /**
     * The scalar result in the closest node as indicated by {@link nodeId}/{@link nodeIndex}.
     */
    nodeScalarResult: number | undefined;
    /**
     * The id of the element in the data model on the server that was hit
     */
    elementId: number;
    /**
     * The index of the element in the data model on the server that was hit
     */
    elementIndex: number;
    /**
     * The type of the element in the data model on the server that was hit, for example 'Quad', 'Tetrahedron', 'Hexahedron'
     */
    elementType: string;
    /**
     * The type of the element in the data model on the server that was hit, for example 'Quad', 'Tetrahedron', 'Hexahedron'
     */
    elementLocalSurface: number;
    /**
     * The scalar result in the closest node as indicated by {@link nodeId}/{@link nodeIndex}.
     */
    elementScalarResult: number | undefined;
    /**
     * The 3d point (in world coordinates) on the surface that was hit.
     *
     * This is the actual point that was hit
     */
    intersectionPoint: Vec3;
    /**
     * The normal of the surface at the point where the surface was hit.
     */
    intersectionPointNormal: Vec3 | null;
    /**
     * A tessellation of triangles of the element that was hit.
     *
     * This array contains x,y,z values for each triangle vertex. So there will be 9 values (3 vertices * (x,y,z)) per triangle.
     * This can be used to highlight the selected element using the geometry or the markup model.
     */
    elementTriangleVertices: number[];
    /**
     * Object identifying the hit item. Can be used for query
     */
    serverItemIdent: ServerItemIdent;
}

/**
 *
 */
export class Isosurface {
    /**
     *
    */
    private constructor();
    /**
     *
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * The result id of the scalar result mapped on the isosurface.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapScalarResultId(): number;
    /**
     * The result id of the vector result mapped on the isosurface.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapVectorResultId(): number;
    /**
     * The result id of the scalar result shown as contour lines on the isosurface.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapContourLinesResultId(): number;
    /**
     * Whether the isosurface should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
}

/**
 *
 */
export class Isovolume {
    /**
     *
    */
    private constructor();
    /**
     * The result id of the scalar result mapped on the isovolume.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapScalarResultId(): number;
    /**
     * The result id of the vector result mapped on the isovolume.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapVectorResultId(): number;
    /**
     * The result id of the scalar result shown as contour lines on the isovolume.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapContourLinesResultId(): number;
    /**
     *
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * Whether the isovolume should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
}

/**
 *  Information about the results used on the model.
 *
 * Provides ids of the scalar, vector, displacements results mapped onto the model.
 */
export class ModelSpec {
    /**
     *
    */
    private constructor();
    /**
     * The result id of the scalar shown as fringes (mapped on the surface) on the model.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get fringesResultId(): number;
    /**
     * The result id of the scalar shown as fringes (mapped on the surface) on the model.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get contourLinesResultId(): number;
    /**
     * The result id of the scalar shown as fringes (mapped on the surface) on the model.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get vectorResultIdArr(): ReadonlyArray<number>;
    /**
     * The result id of the scalar shown as fringes (mapped on the surface) on the model.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get displacementResultId(): number;
    /**
     * Returns the id of the scalar result shown on the given part. Will return fringesResultId if no override result was
     * specified for the given part.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    getEffectiveFringesResultId(geometryIndex: number, partId: number): number;
}

/** @module cee.cug */ /** */
/**
 * Object type.
 */
export enum ObjectType {
    /** Normal (FEA) part */
    PART = 0,
    /** Cutting plane */
    CUTTING_PLANE = 1,
    /** Isosurface */
    ISOSURFACE = 2,
    /** Isovolume */
    ISOVOLUME = 3
}

/**
 *
 */
export class Part {
    /**
     *
    */
    private constructor();
    /**
     * The index of the geometry in which the part belongs
    */
    get geometryIndex(): number;
    /**
     * The index of the part within the given geometry
     *
     * See also geometryIndex
    */
    get index(): number;
    /**
     * The ID of the part within the given geometry
    */
    get id(): number;
    /**
     * The name of the part
    */
    get name(): string;
    /**
     * The visibility of the part
     */
    get visible(): boolean;
    set visible(visible: boolean);
    /**
     * Show the element mesh on the surface of the part
     */
    get surfaceMesh(): boolean;
    set surfaceMesh(mesh: boolean);
    /**
     * Whether the part should be highlighted.
     */
    get highlight(): boolean;
    set highlight(highlight: boolean);
}

/**
 *
 */
export class ParticleTraceGroup {
    /**
     *
    */
    private constructor();
    /**
     * The result id of the vector result used to compute the particle trace.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get vectorResultId(): number;
    /**
     * The result id of the scalar result mapped on the particle trace.
     *
     * Use the {@link ConstantRemoteModel.getResultInfo} method to get information about the result.
     */
    get mapScalarResultId(): number;
    /**
     *
    */
    get seedPointArray(): ReadonlyArray<Vec3Like>;
    /**
     *
     */
    get visible(): boolean;
    set visible(visible: boolean);
}

/** @module cee.cug */ /** */
/**
 * The result of a {@link QueryNodeScalarTimeHistory}.
 */
export interface QueryNodeScalarTimeHistoryData {
    /**
     * Ident of the node on which the query was performed
     */
    serverIdent: ServerItemIdent;
    /**
     * The state reference values (usually time)
     */
    xValues: number[];
    /**
     * The scalar value in the node for each state in {@link xValues}
     */
    yValues: number[];
}
/**
 * Callback function invoked when the result of a {@link QueryNodeScalarTimeHistory} is ready.
 */
export interface QueryNodeScalarTimeHistoryCallback {
    (data: QueryNodeScalarTimeHistoryData): void;
}
/**
 * Query a scalar result for a given node across all states.
 *
 * Note that the states do not need to be "loaded", i.e. specified in the model spec.
 */
export class QueryNodeScalarTimeHistory extends RemoteQuery {
    /**
     *
     */
    constructor(model: ConstantRemoteModel);
    /**
     * Executes the query for the given result and node.
     */
    executeQuery(serverIdent: ServerItemIdent, callback: QueryNodeScalarTimeHistoryCallback): void;
}

/**
 * Base class for classes implementing queries to the ConstantRemoteModel on the REST API CUG server.
 */
export abstract class RemoteQuery {
}

/**
 * Type of result (scalar, vector, displacement)
 */
export enum ResultType {
    /**
     * Scalar result. 1 value per item
     */
    SCALAR = 0,
    /**
     * Vector result. 3 values per item
     */
    VECTOR = 1,
    /**
     * Displacement result. 3 values per item
     */
    DISPLACEMENT = 2
}
/**
 * Result position (mapping) of a result
 */
export enum ResultMapping {
    /** One result per node in the part. */
    PER_NODE = 0,
    /** One result per element in the part. */
    PER_ELEMENT = 1,
    /** One result per element node in the part. */
    PER_ELEMENT_NODE = 2,
    /** One result per element surface in the part. */
    PER_SURFACE = 3
}
/**
 *  Information about a given result
 */
export class ResultInfo {
    /**
     *
     */
    private constructor();
    /**
     * The type of result (scalar, vector, displacement)
     */
    get resultType(): ResultType;
    /**
     * The id of the result. Will be unique within each result type.
     */
    get id(): number;
    /**
     * The persistent string id of the result.
     *
     * This is a persistent ID of the result that will not change between versions of EnvisionWeb, and can thus be used to store setting regarding results.
     * The id of the result might change in future versions of EnvisionWeb, and is only guaranteed to be constant in a given version.
     */
    get idString(): string;
    /**
     * The name of the result.
     */
    get name(): string;
    /**
     * Result position (mapping) of the result
     */
    get mapping(): ResultMapping;
    /**
     * The unit of the results (if available).
     */
    get unit(): string;
    /**
     * The minimum value (length for vectors or displacement) of the result
     */
    get minimumValue(): number;
    /**
     * The maximum value (length for vectors or displacement) of the result
     */
    get maximumValue(): number;
}

/**
 * An opaque object identifying a server side item. Can be used for query.
 *
 * Can be found in {@link HitItem.serverItemIdent}
 */
export class ServerItemIdent {
    private constructor();
}

/**
 * Simulation info
 *
 * Information about the source simulation that produced this Constant Remote Model
 */
export class SimulationInfo {
    /**
     *
    */
    private constructor();
    /**
     * The title of the simulation shown in the model
     */
    get title(): string;
    /**
     * The description of the simulation shown in the model
     */
    get description(): string;
    /**
     * The name of the VTFx case shown in the model (if applicable)
     */
    get caseName(): string;
    /**
     * The description of the VTFx case shown in the model (if applicable)
     */
    get caseDescription(): string;
    /**
     * The simulation type of the source model.
     *
     * Possible values:
     * Structural, Thermal, Electric, Magnetic, Fluid, Acoustic, Diffusion, Other
     */
    get simulationType(): string;
    /**
     * The solution type of the source model.
     *
     * Possible values:
     * Static, Steady State, Vibration, Buckling, Transient, Superelement, Frequency response,
     * Complex eigenvalues, Quasi Static, Output, Singular, Other
     */
    get solutionType(): string;
    /**
     * The name of the interface/data provider of this simulation (if applicable)
     */
    get interfaceName(): string;
}

} // cug



//
// pt
// ===================================================================================
export namespace pt {

/** Callback invoked whenever the animation advances to a new frame. */
export interface AnimationFrameChangedCallback {
    (frameIndex: number): void;
}
/**
 * Controls time-step animation of a {@link ParticleModel}.
 *
 * Access via {@link ParticleModel.animation}. Frames advance inside the
 * render loop at the configured {@link targetFrameRate}.
 *
 * @example
 * ```typescript
 * const model = new cee.pt.ParticleModel({ preloadFrameCount: 5 });
 * await model.openModel(url);
 * await model.setFrame(0);
 *
 * model.animation.targetFrameRate = 30;
 * model.animation.runAnimation(true);
 * ```
 */
export class Animation {
    /** True while a setFrame() call is pending. */
    /** Frame index that last triggered a lookahead preload. */
    private constructor();
    /**
     * Target animation speed in frames per second.
     * Actual speed may be lower if data is not yet cached.
     */
    get targetFrameRate(): number;
    set targetFrameRate(fps: number);
    /** Wraps from the last frame to the first. Default `true`. */
    get loop(): boolean;
    set loop(value: boolean);
    /**
     * Frames to advance per step. Default `1`.
     *
     * E.g. stride 5 with `targetFrameRate = 30` gives a 150x speedup.
     * Also used by {@link setNextFrame} and {@link setPreviousFrame}.
     */
    get frameStride(): number;
    set frameStride(value: number);
    /** Whether the animation is running. */
    isModelAnimationRunning(): boolean;
    /** Start or stop playback. */
    runAnimation(start: boolean): void;
    /** Register a callback invoked on each frame change. */
    setAnimationFrameChangedCallback(callback: AnimationFrameChangedCallback | null): void;
    /** Seek to the first frame. Stops animation. */
    setFirstFrame(): void;
    /** Seek to the last frame. Stops animation. */
    setLastFrame(): void;
    /** Advance by {@link frameStride} frames. Stops animation. */
    setNextFrame(): void;
    /** Rewind by {@link frameStride} frames. Stops animation. */
    setPreviousFrame(): void;
    /**
     * Trigger a preload batch when less than 20% of the preload window
     * remains cached ahead of `nextFrame`.
     */
    private _checkAndTriggerLookaheadPreload;
    private _stopAndSeek;
}

/** @module cee.pt */ /** */
/** Numeric min/max range. */
export interface ScalarRange {
    min: number;
    max: number;
}
/** Fields shared by DatasetInfo and ScalarFieldUpdate. */
interface ScalarFieldInfo {
    modelKey: string;
    activeScalarField: string | null;
    scalarRange?: ScalarRange;
    scalarFieldNames: string[];
    /** Whether frames include scalar data in the wire format.
     *  - true  -- 12 BPP: id(4) + qx(2) + qy(2) + qz(2) + qScalar(2).
     *  - false -- 10 BPP: id(4) + qx(2) + qy(2) + qz(2). */
    hasScalarData: boolean;
}
/** Metadata about a particle dataset, fetched from the server on open. */
export interface DatasetInfo extends ScalarFieldInfo {
    /** Max particle count across all frames. Used to pre-allocate buffers. */
    maxParticleCount: number;
    /** Total number of time-step frames. */
    frameCount: number;
    /** Bounding box across all frames. Used for initial view framing. */
    boundingBox: BoundingBox;
}
/** Subset of DatasetInfo returned when switching or clearing the active scalar field. */
export interface ScalarFieldUpdate extends ScalarFieldInfo {
}
export {};

/** @module cee.pt */ /** */
/**
 * Called whenever an error occurs during server communication.
 */
export interface ServerErrorHandler {
    (err: Error, model: ParticleModel): void;
}
/**
 * Client-side particle model. Fetches, decodes, caches, and renders time-stepped
 * particle frames via the PtServer REST API (`/api/v1/models`).
 *
 * ```typescript
 * const model = new cee.pt.ParticleModel();
 * await model.openModel('http://server/api/v1/models/mydata.ptfx');
 * await model.setFrame(0);
 * model.closeModel();
 * ```
 */
export class ParticleModel extends Model implements ProcessableModel {
    private modelName;
    private serverComm;
    private frameDecoder;
    private preloadDecoder;
    private frameCache;
    private performanceMonitor;
    private anim;
    private dsInfo;
    private currentFrame;
    private opened;
    private modelKeyStr;
    private props;
    private openAbortController;
    private currentFrameAbortController;
    private preloadAbortController;
    private scalarFieldAbortController;
    private currentSeekToken;
    private scalarOpToken;
    private modelVer;
    private savedActiveScalarField;
    private errorHandler;
    constructor(properties?: Partial<ParticleModelProperties>);
    /** Open a particle dataset from a URL. */
    openModel(datasetUrl: string): Promise<DatasetInfo>;
    /**
     * Load and display a frame. Cancels any previous inflight request.
     * @param frameIndex 0-based index in `[0, frameCount)`
     */
    setFrame(frameIndex: number): Promise<void>;
    /** Close the model and release resources. Error handler is preserved. */
    closeModel(): void;
    isOpen(): boolean;
    get currentFrameIndex(): number;
    get datasetInfo(): DatasetInfo | null;
    get frameCount(): number;
    get maxParticleCount(): number;
    get scalarFieldNames(): string[];
    get activeScalarField(): string | null;
    get name(): string;
    set name(value: string);
    /** The animation controller for this model. */
    get animation(): Animation;
    getParticleSize(): number;
    /** Set point size in pixels (clamped to >= 1). */
    setParticleSize(size: number): void;
    getParticleColor(): Color3Like;
    /** Set solid particle color (used when scalar mapping is off). */
    setParticleColor(color: Color3Like): void;
    /** Get the opacity of the particles. 0 = fully transparent, 1 = fully opaque. */
    getOpacity(): number;
    /** Set the opacity of the particles (clamped to [0, 1]). */
    setOpacity(opacity: number): void;
    getDecimationFactor(): number;
    /** Set server-side decimation factor [0.01, 1.0]. Invalidates cache and reloads current frame. */
    setDecimationFactor(factor: number): void;
    /**
     * Set the number of frames to preload ahead. 0 disables preloading.
     * Takes effect immediately: if the model is open and a frame is loaded,
     * a new preload batch is started from the current frame.
     */
    setPreloadFrameCount(count: number): void;
    getUseScalarMapping(): boolean;
    /**
     * Enable or disable scalar-based color mapping.
     * Toggles the server wire format between 12 BPP (scalar) and 10 BPP (position-only).
     */
    setUseScalarMapping(enable: boolean): Promise<void>;
    /** Switch active scalar field on the server. Invalidates cache and reloads current frame. */
    setActiveScalarField(fieldName: string): Promise<void>;
    getScalarMapper(): ScalarMapper | undefined;
    /** Set scalar mapper for color mapping. */
    setScalarMapper(mapper: ScalarMapper): void;
    /** Per-frame scalar range de-quantized from uint16 via the global range. */
    getCurrentFrameScalarRange(): {
        min: number;
        max: number;
    } | null;
    /** Set error handler. Persists across close/open cycles. Pass `null` to clear. */
    setServerErrorHandler(handler: ServerErrorHandler | null): void;
    getBoundingBox(options?: ModelBoundingBoxOptions): BoundingBox;
    getDefaultCameraConfig(): CameraConfig | null;
}

/** @module cee.pt */ /** */
/** Performance metrics for a single frame load. */
export interface FrameMetrics {
    frameIndex: number;
    downloadMs: number;
    decodeMs: number;
    applyMs: number;
    totalMs: number;
    bytes: number;
    /** Compressed on-the-wire size. Undefined on cache hit or when unavailable. */
    transferBytes?: number;
    particleCount: number;
    cacheHit: boolean;
    timestamp: number;
}
/** Configuration options for ParticleModel. */
export interface ParticleModelProperties {
    /** Point size for GL_POINTS rendering. @default 1.0 */
    particleSize?: number;
    /** Solid color when useScalarMapping is false. @default white (1,1,1) */
    particleColor?: Color3;
    /** Opacity of the particles. 0 = fully transparent, 1 = fully opaque. @default 1.0 */
    opacity?: number;
    /** Whether to use scalar mapping for colors. @default false */
    useScalarMapping?: boolean;
    /** Scalar mapper for color mapping. */
    scalarMapper?: ScalarMapper;
    /** Server-side decimation factor in [0.01, 1.0]. @default 1.0 (all particles) */
    decimationFactor?: number;
    /** Max decoded-frame cache size in MB. LRU eviction when exceeded. @default 2048 */
    maxCacheMemoryMB?: number;
    /** Frames to preload ahead of the current frame. 0 disables preloading. @default 100 */
    preloadFrameCount?: number;
    /** Callback for per-frame performance metrics. */
    onMetrics?: (metrics: FrameMetrics) => void;
    /** Enable console logging of metrics. @default false */
    debugLogging?: boolean;
}
/** Utility: makes every field in T required except those in K, which stay as-is. */
export type RequireAllExcept<T, K extends keyof T> = Required<Omit<T, K>> & Pick<T, K>;
/** Default property values. */
export const DEFAULT_PARTICLE_MODEL_PROPERTIES: RequireAllExcept<ParticleModelProperties, 'scalarMapper' | 'onMetrics'>;

} // pt



//
// vs
// ===================================================================================
export namespace vs {

/** @module cee.vs */ /** */
/**
 * An object describing the result of a picking action on a {@link StreamModel}.
 *
 * Returned by {@link StreamModel.rayIntersect}
 */
export interface HitItem {
    /**
     * The resource key of the group that the hit's instance belongs to.
     */
    groupResourceKey: ResourceKey;
    /**
     * An index of the instance hit within the {@link groupResourceKey}.
     */
    instanceIdx: number;
    /**
     * Intersection point of the hit in world coordinates.
     */
    intersectionPoint: Vec3;
    /**
     * The normal at the intersectionPoint.
     */
    intersectionPointNormal: Vec3 | null;
    /**
     * Centroid of the polygon which was hit.
     */
    polygonCentroid: Vec3;
    /**
     * The user assigned userRef string for the mesh instance that was hit.
     */
    instanceUserRef: string | null;
    /**
     * The user specified userRef string of the referenced polygon's mesh.
     */
    meshUserRef: string | null;
    /**
     * The source id of the polygon that was hit, -1 if not specified
     */
    srcPolyId: number | null;
    /**
     * The source id of the closest vertex, -1 if not specified
     */
    srcVertexId: number | null;
}

/** @module cee.vs */ /** */
/**
 * The information about a single stream.
 */
export interface StreamInfo {
    /**
     * The id of the stream. Use this streamId to create a {@link StreamModel} from this stream.
     */
    streamId: string;
    /**
     * The stream's display name.
     */
    displayName: string;
}
/**
 * A ServerSession object is the first object that needs to be initialized when working with the {@link StreamModel}.
 * It manages the communication with the Visualization Streamer (VizStreamer) service.
 *
 * The {@link getAvailableStreams_async} method is used to get the information about all available streams.
 * These streams can be subsequently used to create {@link StreamModel} instance(s) with the method {@link createStreamModel}.
 *
 * **Example:**
 *  Create a ServerSession and a StreamModel from the first available stream.
 *
 *```typescript
 * // Connect to the server session at the given url.
 * const serverSession = await cee.vs.ServerSession.createInstance_async("http://localhost:8091");
 * // Get the available streams
 * const streams = await serverSession.getAvailableStreams_async();
 *
 * if (streams[0]) {
 *     const streamId = streams[0].streamId;
 *     const streamModel = serverSession.createStreamModel(streamId);
 *
 *     // Add the model to the cee.View
 *     this.view.addModel(streamModel);
 *     // Start the streaming if not already started.
 *     if (!streamModel.isStreamingActive()) {
 *         await streamModel.startStreaming_async();
 *     }
 * }
 * ```
 */
export class ServerSession {
    /**
     * Creates a new ServerSession instance.
     *
     * @param serverUrl The url on which the VizStreamer'sHTTP stream server resides, e.g. `http://localhost:8091`
     */
    static createInstance_async(serverUrl: string): Promise<ServerSession | null>;
    /**
     * Gets the url of the HTTP stream server that this ServerSession is connected to.
     */
    getServerUrl(): string;
    /**
     * Gets the information about all the streams available in the VizStreamer Service.
     * Returns a {@link StreamInfo} array on success, otherwise throws an error (e.g. connection problems).
     */
    getAvailableStreams_async(): Promise<StreamInfo[]>;
    /**
     * Creates a new {@link StreamModel} for the given stream id.
     * Streaming of data into the new model is not started by default, but should be initiated
     * by calling {@link StreamModel.startStreaming_async}.
     */
    createStreamModel(streamId: string): StreamModel;
    /**
     * Destroys this ServerSession instance.
     *
     * This will detach all StreamModels from the session and free all resources associated with the session.
     * After calling this method, the ServerSession instance should not be used anymore.
     */
    destroySession(): void;
}

export type StreamResOk = {
    status: "ok";
    streamRevision: number;
    publishTag: string | null;
};
export type StreamResError = {
    status: "error";
    streamRevision: number;
    error: Error;
};
export type StreamResRevisionObsolete = {
    status: "revisionObsolete";
    supersededByStreamRevision: number;
};
export type ConfigReadyResult = StreamResOk;
export type RevisionBoundConfigReadyResult = StreamResOk | StreamResRevisionObsolete;
export type StreamingCompleteResult = StreamResOk | StreamResError;
export type RevisionBoundStreamingCompleteResult = StreamResOk | StreamResError | StreamResRevisionObsolete;
export type ConfigReadyCallback = (streamResult: ConfigReadyResult) => void;
export type RevisionBoundConfigReadyCallback = (streamResult: RevisionBoundConfigReadyResult) => void;
export type StreamingCompleteCallback = (streamResult: StreamingCompleteResult) => void;
export type RevisionBoundStreamingCompleteCallback = (streamResult: RevisionBoundStreamingCompleteResult) => void;
export type CallbackOptions = {
    oneShot?: boolean;
    matchPublishTag?: string;
};
/**
 * A remote Visualization Streamer (VizStreamer) model that can be displayed in the Viewer.
 *
 * The `StreamModel` class supports an efficient streaming and rendering of 3D data. The data to this model is sent from
 * the VizStreamer Service, to which data is sent using GRPC or a C++ interface.
 *
 * To create a new instance of the `StreamModel`, the {@link ServerSession} object needs to be created first. Afterwards,
 * use the {@link ServerSession.createStreamModel} method to create a model linked to the stream. By default, the model
 * starts streaming immediately.
 *
 * The streaming to this model is controlled with the {@link startStreaming} and {@link stopStreaming} methods.
 * You can also check whether streaming is active with the {@link isStreamingActive} method.
 *
 * The current frame of the StreamModel can be set with the {@link currentFrameIndex} property.
 *
 * **Example:**
 *
 *  Create a StreamModel and add it to the view.
 *
 *```typescript
 * // create a cloud session first, viewer and a view
 * const cloudSession = new cee.CloudSession();
 * const viewer = cloudSession.addViewer(htmlCanvasElement, { useOperators: false });
 * const view = viewer.addView()
 *
 * // Connect to the server session at the given url.
 * const serverSession = await cee.vs.ServerSession.createInstance_async("http://localhost:8091");
 * // Get the available streams
 * const streams = await serverSession.getAvailableStreams_async();
 *
 * // Grab the first stream
 * if (streams[0]) {
 *     const streamId = streams[0].streamId;
 *     const streamModel = serverSession.createStreamModel(streamId);
 *
 *     // Add the model to the cee.View
 *     view.addModel(streamModel);
 *     // Start the streaming if not already started.
 *     if (!streamModel.isStreamingActive()) {
 *         await streamModel.startStreaming_async();
 *     }
 * }
 * ```
 */
export class StreamModel extends Model implements ProcessableModel {
    /**
     * Name of the model, primarily used for debugging.
     */
    get name(): string;
    set name(name: string);
    /**
     * The stream id of the stream being consumed by this model
     */
    get streamId(): string;
    /**
     * The current streamRevision of the stream being consumed by this model, or undefined if no stream
     * config has been received yet.
     */
    get streamRevision(): number | undefined;
    /**
     * The publishTag associated with the current stream config or null if no publishTag was set.
     */
    get publishTag(): string | null;
    /**
     * Starts the streaming from the VizStreamer Service.
     */
    startStreaming_async(): Promise<boolean>;
    /**
     * Stops the streaming from the VizStreamer Service.
     */
    stopStreaming(): void;
    /**
     * Checks whether the streaming to the model is enabled or not.
     */
    isStreamingActive(): boolean;
    /**
     * Detaches the model from its owner server session.
     * This will permanently stop streaming of the model.
     */
    detachFromSession(): void;
    /**
     * Sets the guiding camera by watching its changes and using it to guide the streaming.
     */
    setGuidingCamera(camera: Camera): void;
    /**
     *
     */
    isStreamingComplete(): boolean;
    /**
     *
     */
    addConfigReadyCallback(callback: ConfigReadyCallback): void;
    addConfigReadyCallback(options: CallbackOptions, callback: ConfigReadyCallback): void;
    /**
     *
     */
    addStreamingCompleteCallback(callback: StreamingCompleteCallback): void;
    addStreamingCompleteCallback(options: CallbackOptions, callback: StreamingCompleteCallback): void;
    /**
     *
     */
    addConfigReadyCallbackForRevision(streamRevision: number, callback: RevisionBoundConfigReadyCallback): void;
    /**
     *
     */
    addStreamingCompleteCallbackForRevision(streamRevision: number, callback: RevisionBoundStreamingCompleteCallback): void;
    /**
     *
     */
    removeAllConfigReadyCallbacks(): void;
    /**
     *
     */
    removeAllStreamingCompleteCallbacks(): void;
    /**
     * Gets the number of frames in this model.
     */
    get frameCount(): number;
    /**
     * Gets/sets the current frame index displayed in this model.
     */
    get currentFrameIndex(): number;
    set currentFrameIndex(frameIndex: number);
    /**
     * Polls for new data for this model.
     */
    pollForStreamConfig_async(): Promise<void>;
    /**
     * Returns the {@link BoundingBox} (in world coordinates) of the current contents of the model
     *
     * Note that this method does not support any {@link ModelBoundingBoxOptions}
     */
    getBoundingBox(_options?: ModelBoundingBoxOptions): BoundingBox;
    /**
     * Returns default camera configuration, which is always null for this model.
     */
    getDefaultCameraConfig(): null;
    /**
     * Performs picking on the model using the current frame. Returns null when nothing is hit.
     */
    rayIntersect(ray: Ray): HitItem | null;
}

/** @module cee.vs */ /** */
/**
 * Resource key is a unique indentifier for objects pushed to the VizStreamer Service.
 */
export type ResourceKey = string;

/**
 * The **vs** sub-module provides a streaming model designed to work in pair with the Visualization Streamer
 * Service (VizService) to which it requires a live connection. It handles fast and efficient streaming of 3D data to web
 * while being specifically tailored towards showing CAE visualizations.
 *
 * For any visualization to be streamed to the client, VizService must be running on the server side an data must be
 * pushed towards it from an application or other service running on the server side. That is done via gRPC
 * or a C++ interface. For more information, please see the Visualization Streamer documentation page.
 *
 * the vs module may be referenced using the `cee.vs` prefix, e.g.:
 *
 * ```javascript
 * const serverSession = await cee.vs.ServerSession.createInstance_async("http://localhost:8091");
 * ```
 *
 * We provide a complete minimal example of how to use this module in the `Examples/MinimalVsClient` folder inside the distribution package.
 *
 * @module cee.vs
 *
 */ /** */

} // vs

