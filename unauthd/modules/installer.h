
@interface Installer : NSObject

+ (void)installPKG: (NSString *)path withAuthorization: (AuthorizationRef *)authRef toDest: (NSString *)dest;

@end

@interface InstallDelegate : NSObject

- (void)installClientDidFinish:(id)arg1;
- (void)installClient:(id)arg1 didFailWithError:(NSError *)error;
- (void)installClientDidBegin:(id)arg1;

@end

typedef struct {
    unsigned int val[8];
} CDStruct_4c969caf;

typedef struct {
    unsigned int _field1;
    uint64_t *_field2;
} CDStruct_166d2db6;

@interface PKDistribution : NSObject <NSSecureCoding, NSCopying>
{
    NSXMLDocument *_xmlDocument;
    NSMutableDictionary *_choicesByIdentifier;
    NSMutableDictionary *_pkgRefsByIdentifier;
    NSMutableArray *_pkgRefsInOrder;
    NSMutableDictionary *_stringsDictionaryByLocalization;
}

+ (id)_element:(id)arg1 coalescedAttributesDictionaryWithChildrenNamed:(id)arg2;
+ (id)maxSupportedSpecVersion;
+ (BOOL)supportsSecureCoding;
- (id)bridgeBuildGroup;
- (id)bridgeBuildVersion;
- (id)bridgeElement;
- (id)localizedStringForKey:(id)arg1 value:(id)arg2;
- (void)setStringsDictionary:(id)arg1 forLocalization:(id)arg2;
- (id)stringsDictionaryForLocalization:(id)arg1;
- (id)_stringsElementForLocalization:(id)arg1;
- (id)localizations;
- (id)searchAttributesForIdentifier:(id)arg1;
- (id)_searchAttributeDictionaryForSearchElement:(id)arg1;
- (id)orderedSearchIdentifiers;
- (void)_setEnabledValue:(id)arg1 forDomain:(int)arg2;
- (void)setEnabledValue:(id)arg1 forDomain:(int)arg2;
- (id)enabledScriptForDomain:(int)arg1 creatingIfNeeded:(BOOL)arg2;
- (id)enabledValueForDomain:(int)arg1;
- (id)_attributeNameForDomain:(int)arg1;
- (id)_choicesUsingPackageReference:(id)arg1;
- (id)allPackageIdentifiers;
- (id)packageReferenceForIdentifier:(id)arg1;
- (void)removeObjectFromPackageReferencesAtIndex:(unsigned long long)arg1;
- (void)insertObject:(id)arg1 inPackageReferencesAtIndex:(unsigned long long)arg2;
- (id)objectInPackageReferencesAtIndex:(unsigned long long)arg1;
- (unsigned long long)countOfPackageReferences;
- (void)_didChangePkgRef:(id)arg1 originalIdentifier:(id)arg2 insertIndex:(unsigned long long)arg3;
- (id)_pkgRefsInOrder;
- (id)_pkgRefsByIdentifier;
- (void)__cachePkgRefElement:(id)arg1;
- (id)resourceEnabledScriptForKey:(id)arg1;
- (id)_futureSystemVersionDictionary;
- (void)setRequiredBundleComponents:(id)arg1 requireAll:(BOOL)arg2 description:(id)arg3;
- (id)descriptionOfRequiredBundleComponents;
- (BOOL)requireAllBundleComponents;
- (id)requiredBundleComponents;
- (id)_minimumRequiredOSVersion;
- (void)setSupportedOSVersions:(id)arg1;
- (id)supportedOSVersions;
- (id)peripheralCheckScriptCreatingIfNeeded:(BOOL)arg1;
- (id)upgradeCheckScriptCreatingIfNeeded:(BOOL)arg1;
- (id)volumeCheckScriptCreatingIfNeeded:(BOOL)arg1;
- (void)setDescriptionOfRequiredHardwareProperties:(id)arg1;
- (id)descriptionOfRequiredHardwareProperties;
- (void)setDescriptionOfRequiredGraphicsHardware:(id)arg1;
- (id)descriptionOfRequiredGraphicsHardware;
- (void)setRequireSingleGraphicsDevice:(BOOL)arg1;
- (BOOL)requireSingleGraphicsDevice;
- (void)setRequiredMetalDevicePredicate:(id)arg1;
- (id)requiredMetalDevicePredicate;
- (void)setRequiredCLDevicePredicate:(id)arg1;
- (id)requiredCLDevicePredicate;
- (void)setRequiredGLRendererPredicate:(id)arg1;
- (id)requiredGLRendererPredicate;
- (void)_setRequiredGraphicsPredicate:(id)arg1 ofType:(id)arg2;
- (id)_requiredGraphicsPredicateOfType:(id)arg1;
- (void)setRequiredHardwarePropertiesPredicate:(id)arg1;
- (id)requiredHardwarePropertiesPredicate;
- (void)setRequiredGigaBytesOfRAM:(id)arg1;
- (id)requiredGigaBytesOfRAM;
- (id)installationCheckScriptCreatingIfNeeded:(BOOL)arg1;
- (id)peripheralCheckScript;
- (id)upgradeCheckScript;
- (id)volumeCheckScript;
- (id)installationCheckScript;
- (id)topScript;
- (id)_scriptUnder:(id)arg1 element:(id)arg2 attribute:(id)arg3 createIfNeeded:(BOOL)arg4;
- (void)setAuxInfoPropertyList:(id)arg1;
- (id)auxInfoPropertyList;
- (void)setTags:(id)arg1;
- (id)tags;
- (void)setOptionsDictionary:(id)arg1;
- (id)optionsDictionary;
- (void)setIOMatchingDictionary:(id)arg1;
- (id)ioMatchingDictionary;
- (void)_verifyAndRepairChoiceTreeWithReferencingElement:(id)arg1 movedOrSynthesizedChoices:(id *)arg2;
- (void)_findIncorrectlyNestedChoicesUnder:(id)arg1 addTo:(id)arg2;
- (void)_verifyAndRepairChoiceTreeForInterfaceType:(id)arg1;
- (id)choiceForIdentifier:(id)arg1;
- (id)rootChoiceForInterfaceType:(id)arg1 creatingIfNeeded:(BOOL)arg2;
- (id)interfaceTypes;
- (id)_choicesOutlineElementForInterfaceType:(id)arg1 creatingIfNeeded:(BOOL)arg2;
- (void)_didChangeChoice:(id)arg1 originalIdentifier:(id)arg2;
- (id)_choicesByIdentifier;
- (void)__cacheLineElements:(id)arg1;
- (void)setResourceAttributes:(id)arg1 forKey:(id)arg2;
- (id)resourceAttributesForKey:(id)arg1;
- (void)setResourceData:(id)arg1 forKey:(id)arg2;
- (id)resourceDataForKey:(id)arg1;
- (void)setVersionKey:(id)arg1;
- (id)versionKey;
- (void)setTitleKey:(id)arg1;
- (id)titleKey;
- (void)_setSystemImagePackageReferences:(id)arg1;
- (void)_setSystemImageInformation:(id)arg1;
- (id)_systemImagePackageReferences;
- (id)_systemImageInformation;
- (void)setProductVersion:(id)arg1;
- (void)setProductIdentifier:(id)arg1;
- (id)productVersion;
- (id)productIdentifier;
- (id)objectForSourceURI:(id)arg1 returningAttributeName:(id *)arg2;
- (void)setPlatformAttributes:(id)arg1 forType:(id)arg2;
- (id)platformAttributesForType:(id)arg1;
- (id)_rootElement;
- (void)setMinSpecVersion:(id)arg1;
- (id)minSpecVersion;
- (id)_minSpecVersionAddingSupportedOSVersionIfNeeded:(BOOL)arg1;
- (double)_currentMinSpecVersionReturningSupportedOSVersion:(id *)arg1;
- (void)_setDistributionURL:(id)arg1;
- (id)XMLData;
- (id)distributionURL;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithData:(id)arg1 error:(id *)arg2;
- (id)initWithContentsOfURL:(id)arg1 error:(id *)arg2;
- (id)init;
- (id)_initWithXMLDocument:(id)arg1 error:(id *)arg2;

@end


@interface PKDistributionContainer : NSObject
{
    PKDistribution *_distribution;
}

+ (id)localizationNamesAtPath:(id)arg1;
+ (id)_lprojSubpathsInDirectory:(id)arg1;
- (id)resourceDataForKey:(id)arg1 returningMIMEType:(id *)arg2 returningUTI:(id *)arg3;
- (id)_resourceContentType:(id)arg1 forKey:(id)arg2;
- (id)_resourceDataForKey:(id)arg1;
- (id)localizedStringForKey:(id)arg1 value:(id)arg2;
- (id)stringsDictionary;
- (id)distribution;
- (void)dealloc;
- (id)initWithArchive:(id)arg1 error:(id *)arg2;
- (id)initWithPath:(id)arg1 error:(id *)arg2;
- (id)initWithDistributionData:(id)arg1 distributionURL:(id)arg2 error:(id *)arg3;
- (id)_initWithDistributionData:(id)arg1 distributionURL:(id)arg2 error:(id *)arg3;

@end

@interface PKProduct : NSObject
{
    int _minTrustLevel;
    int _evaluatedTrustLevel;
    NSArray *_certificateChain;
    struct __SecTrust *_trustRef;
    BOOL _allowExpiredCerts;
    BOOL _allowExpiredRoots;
}

+ (BOOL)canInitWithURL:(id)arg1;
+ (id)productByLoadingProductAtURL:(id)arg1 error:(id *)arg2;
+ (id)_allProductClasses;
+ (void)_setAllowsFolderArchives:(BOOL)arg1;
+ (BOOL)_allowsFolderArchives;
@property(readonly) NSArray *allPackageReferences;
- (id)resourceDataForKey:(id)arg1 returningMIMEType:(id *)arg2 returningUTI:(id *)arg3;
- (id)localizedStringForKey:(id)arg1 value:(id)arg2;
@property(readonly) NSDictionary *stringsDictionary;
@property(readonly) PKDistributionContainer *distributionContainer;
@property(readonly) PKDistribution *distribution;
- (void)setAllowExpiredRoots:(BOOL)arg1;
- (void)setAllowExpiredCertificates:(BOOL)arg1;
- (int)trustLevelReturningTrustRef:(struct __SecTrust **)arg1;
- (int)trustLevelReturningCertificateChain:(id *)arg1;
- (BOOL)evaluateTrustReturningError:(id *)arg1;
- (void)setMinimumRequiredTrustLevel:(int)arg1;
@property(readonly) NSString *productVersion;
@property(readonly) NSString *productIdentifier;
@property(readonly) NSString *productType;
@property(readonly) NSURL *URL;
- (void)dealloc;
- (id)_archiveForTrustEvaluation;
- (id)initByLoadingProductAtURL:(id)arg1 error:(id *)arg2;
- (id)_distributionFlatData;
- (id)_distributionArchivePath;

@end



@interface PKArchive : NSObject
{
}

+ (id)archiveWithPath:(id)arg1 options:(id)arg2;
+ (id)archiveWithPath:(id)arg1;
+ (id)_allArchiveClasses;
- (BOOL)closeArchive;
- (BOOL)fileExistsAtPath:(id)arg1;
- (BOOL)verifyReturningError:(id *)arg1;
- (id)fileAttributesAtPath:(id)arg1;
- (BOOL)extractItemAtPath:(id)arg1 toPath:(id)arg2 error:(id *)arg3;
- (id)dataForPath:(id)arg1;
- (id)enumeratorAtPath:(id)arg1;
- (id)computedArchiveDigestWithAlgorithm:(id)arg1;
@property(readonly) NSString *archiveDigest;
@property(readonly) NSData *archiveDigestData;
@property(readonly) NSString *archivePath;
- (id)description;
- (BOOL)_extractFile:(id)arg1 toPath:(id)arg2 error:(id *)arg3;
- (id)initForReadingFromPath:(id)arg1 options:(id)arg2;
- (id)initForReadingFromPath:(id)arg1;
@property(readonly) NSDate *archiveSignatureDate;
@property(readonly) NSArray *archiveSignatures;

@end


@interface PKPackageInfo : NSObject
{
    NSXMLDocument *_XMLDocument;
}

+ (id)_bundleIdentifierFromBundleElement:(id)arg1;
- (void)setValue:(id)arg1 forKey:(id)arg2;
- (id)valueForKey:(id)arg1;
@property(readonly) NSXMLDocument *XMLDocument;
- (void)dealloc;
- (id)initWithIdentifier:(id)arg1;
- (id)initWithIdentifier:(id)arg1 version:(id)arg2;
- (id)initWithData:(id)arg1;
- (id)_initWithXMLDocument:(id)arg1;
- (void)_setDontObsoletePathsWithSet:(id)arg1;
- (void)_setFileElementTurdsWithComponents:(id)arg1;
- (void)_setComponentScriptsWithComponents:(id)arg1;
- (void)_setBundleIdentifiersAsRelocatable:(id)arg1;
- (void)_setBundleIdentifiersForStrict:(id)arg1;
- (void)_setBundleIdentifiersForAtomicUpdate:(id)arg1;
- (void)_setBundleIdentifiersForUpdate:(id)arg1;
- (void)_setBundleIdentifiersForUpgrade:(id)arg1;
- (void)_setBundleIdentifiersForVersionChecking:(id)arg1;
- (void)__setBundleIdentifiers:(id)arg1 forDirective:(id)arg2;
- (void)_setBundleDefinitionsWithBundleAttributeDictionaries:(id)arg1;
- (void)setGroups:(id)arg1;
- (id)groups;
- (void)setstaticObsoleteFileOrRecursiveDirectoryListPath:(id)arg1;
- (id)staticObsoleteFileOrRecursiveDirectoryListPath;
- (void)setStaticObsoleteDirectoryListPath:(id)arg1;
- (id)staticObsoleteDirectoryListPath;
- (void)setStaticObsoleteFileListPath:(id)arg1;
- (id)staticObsoleteFileListPath;
- (void)setPostInstallScriptPath:(id)arg1;
- (void)setPostinstallScriptPath:(id)arg1;
- (id)postInstallScriptPath;
- (id)postinstallScriptPath;
- (void)setPreInstallScriptPath:(id)arg1;
- (void)setPreinstallScriptPath:(id)arg1;
- (id)preInstallScriptPath;
- (id)preinstallScriptPath;
- (id)_lastElementForScriptName:(id)arg1 componentIdentifier:(id)arg2 createIfNeeded:(BOOL)arg3;
- (void)setUpdatePayloadSize:(unsigned long long)arg1;
- (unsigned long long)updatePayloadSize;
- (void)setPayloadFileCount:(unsigned long long)arg1;
- (unsigned long long)payloadFileCount;
- (void)setPayloadInstallSize:(unsigned long long)arg1;
- (unsigned long long)payloadInstallSize;
- (void)setPayloadExternalRoot:(id)arg1;
- (id)payloadExternalRoot;
- (void)setUseHFSPlusCompression:(id)arg1;
- (id)useHFSPlusCompression;
- (void)setMinimumSystemVersion:(id)arg1;
- (id)minimumSystemVersion;
- (void)setGeneratorVersion:(id)arg1;
- (id)generatorVersion;
- (void)setRequiresDistributionCheck:(BOOL)arg1;
- (BOOL)requiresDistributionCheck;
- (void)setUpdatePackage:(BOOL)arg1;
- (BOOL)updatePackage;
- (void)setSystemVolumeGroupInstallLocation:(id)arg1;
- (id)systemVolumeGroupInstallLocation;
- (void)setInstallLocation:(id)arg1;
- (id)installLocation;
- (void)setRestartAction:(int)arg1;
- (int)restartAction;
- (void)setAuthLevel:(int)arg1;
- (int)authLevel;
- (void)setVersion:(id)arg1;
- (id)version;
- (void)setIdentifier:(id)arg1;
- (id)identifier;
- (void)setPreserveACLs:(BOOL)arg1;
- (BOOL)preserveACLs;
- (void)setPreserveExtAttrs:(BOOL)arg1;
- (BOOL)preserveExtAttrs;
- (void)setContentType:(id)arg1;
- (id)contentType;
- (void)setShouldVerifyArchiveExplicitly:(BOOL)arg1;
- (BOOL)shouldVerifyArchiveExplicitly;
- (void)setScriptsInvalidateReceipt:(BOOL)arg1;
- (BOOL)scriptsInvalidateReceipt;
- (void)setAllowCustomInstallLocation:(BOOL)arg1;
- (BOOL)allowCustomInstallLocation;
- (void)setOverwritePermissions:(BOOL)arg1;
- (BOOL)overwritePermissions;
- (id)_dontObsoleteXMLElement;
- (id)_deferredInstallXMLElement;
- (id)_requiredFilesXMLElement;
- (id)_patchXMLElement;
- (id)_firmwareBundleXMLElements;
- (id)_relocateBundleXMLElements;
- (id)_strictIdentifierBundleXMLElements;
- (id)_bundleAtomicUpdateBundleXMLElements;
- (id)_bundleUpdateBundleXMLElements;
- (id)_bundleUpgradeBundleXMLElements;
- (id)_bundleVersionBundleXMLElements;
- (id)_topLevelBundleXMLElements;
- (id)_rootElement;
- (void)_setDeferredInstallScriptPath:(id)arg1;
- (id)_deferredInstallScriptPath;
- (id)_firmwareBundlesWithComponentMap:(id)arg1;
- (id)_identifierToComponentMapWithPackage:(id)arg1;
- (void)_parseScriptsElementWithComponentMap:(id)arg1;
- (void)_parseFileContainerElement:(id)arg1 container:(id)arg2 componentMap:(id)arg3 pathToComponentMap:(id)arg4;
- (id)__bundlePathToExistingComponentMap:(id)arg1;
- (void)__parseFileElement:(id)arg1 container:(id)arg2 component:(id)arg3;
- (void)_parseRelocateElementsWithComponentMap:(id)arg1;
- (void)_parseBundleDirectiveElementsWithComponentMap:(id)arg1;
- (void)_parseBundleElements:(id)arg1 intoComponentMap:(id)arg2 withPackage:(id)arg3;
- (id)_coalescedBundleElements;
- (id)_coalescedBundleElementsFromElements:(id)arg1 withParentElement:(id)arg2 bundleIdentifierToBundleElementMap:(id)arg3;
- (id)_generatedIdentifierForBundlePath:(id)arg1;
- (id)_looseComponentIdentifier;
- (id)_bundlePathFromBundleElement:(id)arg1;
- (id)componentForIdentifier:(id)arg1;

@end


@interface PKPackage : NSObject <NSCoding, NSCopying>
{
    NSURL *_url;
    NSDictionary *_options;
    PKArchive *_archive;
    PKPackageInfo *_packageInfo;
    NSDictionary *_componentMap;
    NSArray *_firmwareBundleComponents;
    BOOL _populatedSubpaths;
}

+ (id)packageWithURL:(id)arg1 options:(id)arg2;
+ (id)packageWithURL:(id)arg1;
+ (id)packageWithPath:(id)arg1 options:(id)arg2;
+ (id)packageWithPath:(id)arg1;
+ (id)_allPackageClasses;
+ (BOOL)canInitWithURL:(id)arg1;
- (void)enumerateBundleComponentsUsingBlock:(id)arg1;
- (void)_populateComponentSubpaths;
@property(readonly) NSURL *fileURL;
@property(readonly) uint64_t *archive;
- (BOOL)extractFilesForBundleComponent:(id)arg1 toPath:(id)arg2 error:(id *)arg3;
- (id)firmwareComponents;
- (id)subpathsForComponent:(id)arg1;
- (id)componentForIdentifier:(id)arg1;
- (id)components;
- (id)_componentMap;
- (id)directoryEnumerator;
- (id)payloadExtractorWithDestination:(id)arg1 externalRoot:(id)arg2 error:(id *)arg3;
- (id)scriptsExtractorWithDestination:(id)arg1 error:(id *)arg2;
@property(readonly) NSString *scriptsSubpath;
- (id)_scriptsDirectory;
@property(readonly) PKPackageInfo *packageInfo;
@property(readonly) NSString *packageVersion;
@property(readonly) NSString *packageIdentifier;
- (BOOL)isEqual:(id)arg1;
- (unsigned long long)hash;
- (id)description;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)_staticObsoleteFilesOrRecursiveDirectories;
- (id)_staticObsoleteDirectories;
- (id)_staticObsoleteFiles;
- (id)BOMData;
- (id)initWithURL:(id)arg1 options:(id)arg2;
- (id)firmwareComponentsOfType:(long long)arg1;

@end

@interface PKInstallRequest : NSObject <NSSecureCoding>
{
    NSArray *_packageSpecifiers;
    NSString *_destinationPath;
    long long _installPhases;
    BOOL _useForegroundPriorityForStaging;
    double _frameworkVersion;
    NSString *_clientProcessName;
    BOOL _openScripts;
    BOOL _internalBundleVersionChecking;
    NSString *_scriptTargetVolume;
    NSString *_loggingIdentifier;
    BOOL _ignoreIndexBom;
    BOOL _useAFSCByDefault;
    BOOL _isRecursive;
    NSData *_appStoreReceiptData;
    unsigned long long _spaceRequiredForInstall;
    BOOL _clientBlocksRestart;
    int _restartAction;
    NSString *_appPlaceholderPath;
    NSArray *_lockApplicationsDuringInstall;
    NSString *_blacklistPropertyListPath;
    NSFileHandle *_translocationFileHandle;
    BOOL _bypassSystemVolumeEnforcementChecker;
    BOOL _isOSInstall;
    BOOL _isSoftwareUpdateOSInstall;
    BOOL _isOSInstaller;
    NSString *_masterBOMPath;
    unsigned long long _packageExtractorSpeed;
    BOOL _disableAFSC;
    BOOL _isMDMManagedAppInstall;
    NSDictionary *_untrustedEnvironment;
    NSMachPort *_clientBootstrapPort;
    NSMachPort *_clientSecuritySessionPort;
    int _clientUID;
    int _clientGID;
    CDStruct_4c969caf _clientAuditToken;
    CDStruct_166d2db6 *_authorizationEnvironment;
    struct AuthorizationOpaqueRef *_defaultAuthorization;
    struct AuthorizationOpaqueRef *_overrideAuthorization;
    int _minTrustLevel;
    BOOL _allowExpiredCertificates;
    BOOL _allowExpiredRoots;
    BOOL _didPassPreflight;
    BOOL _hasValidTrustLevel;
    int _evaluatedTrustLevel;
    NSArray *_certificateChain;
    struct __SecTrust *_trustRef;
    BOOL _userConsentedInstall;
}

+ (BOOL)supportsSecureCoding;
+ (id)requestWithPackages:(id)arg1 destination:(id)arg2;
@property BOOL userConsentedInstall; // @synthesize userConsentedInstall=_userConsentedInstall;
@property(readonly) CDStruct_4c969caf clientAuditToken; // @synthesize clientAuditToken=_clientAuditToken;
@property long long installPhases; // @synthesize installPhases=_installPhases;
@property(retain) NSString *destinationPath; // @synthesize destinationPath=_destinationPath;
- (BOOL)_restrictedRootEnabled;
- (BOOL)_restrictedRootOverridden;
- (void)_setAppPlaceholderPath:(id)arg1;
- (id)_appPlaceholderPath;
- (void)_setClientBlocksRestart:(BOOL)arg1;
- (BOOL)_clientBlocksRestart;
- (void)_setSpaceRequiredForInstall:(unsigned long long)arg1;
- (unsigned long long)_spaceRequiredForInstall;
- (void)_setRestartAction:(int)arg1;
- (int)_restartAction;
- (void)_setAppStoreReceiptData:(id)arg1;
- (id)_appStoreReceiptData;
- (BOOL)_bypassReadOnlyEnforcementChecker;
- (void)_setBypassReadOnlyEnforcementChecker:(BOOL)arg1;
- (void)_setTranslocationFileHandle:(id)arg1;
- (void)_setInstallBlacklistPlistPath:(id)arg1;
- (id)_installBlacklistPlistPath;
- (void)_setLockApplicationsDuringInstall:(id)arg1;
- (id)_lockApplicationsDuringInstall;
- (void)_setIsRecursive:(BOOL)arg1;
- (BOOL)_isRecursive;
- (void)_setInternalBundleVersionChecking:(BOOL)arg1;
- (BOOL)_internalBundleVersionChecking;
- (void)_setUseHFSPlusCompressionByDefault:(BOOL)arg1;
- (BOOL)_useHFSPlusCompressionByDefault;
- (BOOL)_disableAFSC;
- (void)_setDisableAFSC:(BOOL)arg1;
- (unsigned long long)_extractionSpeed;
- (void)_setExtractionSpeed:(unsigned long long)arg1;
- (void)_setIgnoreIndexBom:(BOOL)arg1;
- (BOOL)_ignoreIndexBom;
- (void)_setUseOpenScriptsDirectory:(BOOL)arg1;
- (BOOL)_useOpenScriptsDirectory;
- (void)_setSkipsVerifyOnUnsignedPackages:(BOOL)arg1;
- (void)_setMasterBOMPath:(id)arg1;
- (id)_masterBOMPath;
- (void)_setScriptTargetVolume:(id)arg1;
- (id)_scriptTargetVolume;
- (void)_setClientUID:(int)arg1 andGID:(int)arg2;
- (int)_clientGID;
- (int)_clientUID;
- (void)_setClientSecuritySessionPort:(id)arg1;
- (id)_clientSecuritySessionPort;
- (void)_setClientBootstrapPort:(id)arg1;
- (id)_clientBootstrapPort;
- (void)_setUntrustedEnvironment:(id)arg1;
- (id)_untrustedEnvironment;
- (id)_installSandboxName;
- (void)_setInstallSandboxName:(id)arg1;
- (BOOL)_isOSInstaller;
- (void)_setIsOSInstaller:(BOOL)arg1;
- (void)_setIsSoftwareUpdateOSInstall:(BOOL)arg1;
- (BOOL)_isSoftwareUpdateOSInstall;
- (BOOL)_isOSInstall;
- (void)_setIsOSInstall:(BOOL)arg1;
- (id)_clientProcessName;
- (BOOL)_useForegroundPriorityForStaging;
- (void)_setUseForegroundPriorityForStaging:(BOOL)arg1;
- (BOOL)_isStageRequest;
- (void)_setIsStageRequest:(BOOL)arg1;
- (void)_setLoggingIdentifier:(id)arg1;
- (id)_loggingIdentifier;
- (id)_installItems;
- (void)removePackageSpecifiers:(id)arg1;
@property(readonly) NSArray *packageSpecifiers;
@property(readonly) NSArray *packages;
- (id)description;
- (BOOL)_isDeeplyEqualToRequest:(id)arg1;
- (BOOL)isEqual:(id)arg1;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)_initWithPackages:(id)arg1 destination:(id)arg2 withOutError:(id *)arg3;
- (id)init;
- (id)initWithPackages:(id)arg1 destination:(id)arg2;
- (BOOL)_isRequestCompatibleWithRights:(id)arg1;
- (BOOL)_validateAuthorizationReturningAcquiredRights:(id *)arg1;
- (BOOL)authorizeForRight:(const char *)arg1 allowingInteraction:(BOOL)arg2;
- (BOOL)preauthorizeAllowingInteraction:(BOOL)arg1;
- (BOOL)requiresAuthorization;
- (int)_authLevel;
- (const struct AuthorizationOpaqueRef *)authorization;
- (void)setAuthorizationEnvironment:(CDStruct_166d2db6 *)arg1;
- (void)setAuthorization:(struct AuthorizationOpaqueRef *)arg1;
- (struct AuthorizationOpaqueRef *)_createAuthorizationRefWithExternalFormData:(id)arg1;
- (id)_externalFormDataForAuthorizationRef:(struct AuthorizationOpaqueRef *)arg1;
- (id)_authorizationAsExternalData;
- (int)trustLevelReturningTrustRef:(struct __SecTrust **)arg1;
- (int)trustLevelReturningCertificateChain:(id *)arg1;
- (BOOL)evaluateTrustReturningError:(id *)arg1;
- (BOOL)_evaluateTrustForPackage:(id)arg1 verifyingPayload:(BOOL)arg2 returningError:(id *)arg3;
- (void)setAllowExpiredRoots:(BOOL)arg1;
- (void)setAllowExpiredCertificates:(BOOL)arg1;
- (void)setMinimumRequiredTrustLevel:(int)arg1;
- (void)_updateWithSingleTrustLevel:(int)arg1 certificateChain:(id)arg2 trust:(struct __SecTrust *)arg3;
- (void)_clearTrustEvaluation;
- (BOOL)_hasValidInstallPathForAnyIAPContent;
- (BOOL)_isValidAppStoreRequest:(BOOL)arg1;
- (BOOL)_isRequestFromMacAppStore;
- (BOOL)_isRequestFromSoftwareUpdate;
- (BOOL)_validAttributesForSoftwareUpdate:(id)arg1;
- (BOOL)didPassPreflightCheck;
- (BOOL)_performPreflightCheckIncludingSizing:(BOOL)arg1 error:(id *)arg2;
- (BOOL)_canInstallPackageSpecifier:(id)arg1 error:(id *)arg2;
- (BOOL)performPreflightCheckReturningError:(id *)arg1;
- (unsigned long long)totalSizeRequired;
- (void)_resolveInstallPathsReplacingPriorResults:(BOOL)arg1;
- (BOOL)checkLocalPackagesReturningError:(id *)arg1;
- (BOOL)_isMDMManagedAppInstall;
- (void)_setIsMDMManagedAppInstall:(BOOL)arg1;

@end

@interface PKInstallClient : NSObject
{
    PKInstallRequest *_installRequest;
    id _delegate;
    BOOL _delegateWantsUpdates;
    id _conn;
    id _installToken;
    NSTimer *_statusTimer;
    double _lastProgress;
    BOOL _isRegistering;
    BOOL _isInitialized;
}

+ (BOOL)_inProcessInstall;
+ (id)_connectToDaemonForAuthLevel:(int)arg1 privileged:(BOOL)arg2 recursiveInstall:(BOOL)arg3 silent:(BOOL)arg4 forInstance:(id)arg5;
+ (BOOL)isCurrentlyStagedInstallRequest:(id)arg1 purgeableSize:(id *)arg2;
+ (double)estimatedTimeForInstallRequest:(id)arg1;
+ (void)_modifyConnectionsForRegisteredAuthorizations:(id)arg1;
+ (void)unregisterAuthorizations;
+ (BOOL)registerAuthorization:(AuthorizationRef *)arg1;
+ (void)initialize;
+ (unsigned long long)purgeableSpaceForOrphanedSandboxesOnVolume:(id)arg1;
+ (unsigned long long)purgeSandboxesOnVolume:(id)arg1 purgeAmountNeeded:(unsigned long long)arg2 systemSandboxes:(BOOL)arg3;
+ (unsigned long long)estimateOfPurgeableSpaceForSandboxesOnVolume:(id)arg1 systemSandboxes:(BOOL)arg2;
- (void)installWillProceedForState:(int)arg1 withSandbox:(id)arg2 forToken:(id)arg3 completion:(id)arg4;
- (void)installDidEndForToken:(id)arg1;
- (void)installDidBeginCommitForToken:(id)arg1;
- (void)installDidBeginForToken:(id)arg1;
- (void)_installDaemonDidEndInstallWithError:(id)arg1 registrationPaths:(id)arg2;
- (id)_localPackageForRemoteSpecifier:(id)arg1;
- (void)_finishInstallClientOnMainThreadWithError:(id)arg1;
- (void)_statusTimerHasFired:(id)arg1;
- (void)_scheduleStatusTimerOnCurrentThread;
- (id)_installStatusByConnectingToDaemon;
- (void)_installDaemonDidBeginInstall_OnMainThread;
@property(readonly) NSArray *displayNames;
@property(readonly) PKInstallRequest *request;
- (void)dealloc;
- (id)_initWithRequest:(id)arg1 options:(unsigned long long)arg2 ignoringBlockingClients:(BOOL)arg3 delegate:(id)arg4 error:(id *)arg5;
- (id)initWithRequest:(id)arg1 delegate:(id)arg2 options:(unsigned long long)arg3 error:(id *)arg4;
- (id)initForCurrentCommitWithDelegate:(id)arg1 ignoringBlockingClients:(BOOL)arg2 error:(id *)arg3;
- (id)initWithRequest:(id)arg1 inUserContext:(BOOL)arg2 holdingBoostDuringInstall:(BOOL)arg3 delegate:(id)arg4 error:(id *)arg5;
- (id)initWithRequest:(id)arg1 inUserContext:(BOOL)arg2 delegate:(id)arg3 error:(id *)arg4;
- (id)initWithRequest:(id)arg1 delegate:(id)arg2 error:(id *)arg3;

@end
