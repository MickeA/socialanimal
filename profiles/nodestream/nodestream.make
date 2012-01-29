; $Id$

; API

api = 2

; Core

core = 7.x

; Stable modules

projects[variable][version] = 1.1
projects[libraries][version] = 1.0
projects[link][version] = 1.0
projects[panels_everywhere][version] = 1.0-alpha1
projects[rules][version] = 2.0
projects[entity][version] = 1.0-rc1
projects[scheduler][version] = 1.0
projects[webform][version] = 3.15
projects[workbench][version] = 1.1
projects[workbench_access][version] = 1.0
projects[workbench_moderation][version] = 1.1
projects[workbench_media][version] = 1.0
projects[diff] = 2.0
projects[entitycache][version] = 1.1
projects[cache_actions][version] = 2.0-alpha3
projects[dynamic_formatters][version] = 2.0-alpha2
projects[field_group][version] = 1.1
projects[features][version] = 1.0-beta4
projects[strongarm][version] = 2.0-beta5
projects[views][version] = 3.0
projects[taxonomy_menu_form][version] = 1.1
projects[file_entity][version] = 2.0-unstable2
projects[devel][version] = 1.2
projects[coder][version] = 1.0
projects[media][version] = 2.0-unstable2
projects[entityreference][version] = 1.0-beta2
projects[token][version] = 1.0-beta7
projects[pathauto][version] = 1.0
projects[flag][version] = 2.0-beta6
projects[references_dialog][version] = 1.0-alpha2
projects[crossclone][version] = 1.0-alpha2

; Stable themes

projects[precision][version] = 1.0-alpha1
projects[ns_theme][version] = 2.0-alpha2

; CTools, needed for bug fixes.
projects[ctools][type] = module
projects[ctools][download][type] = git
projects[ctools][download][url] = http://git.drupal.org/project/ctools.git
projects[ctools][download][revision] = f596653

; UUID
projects[uuid][type] = module
projects[uuid][download][type] = git
projects[uuid][download][url] = http://git.drupal.org/project/uuid.git
projects[uuid][download][revision] = b27dda059eb676ff16122d39aaf6c333fdea81ce

; Views RSS, has no stable 7.x release yet but a patch will do the trick.
projects[views_rss][type] = module
projects[views_rss][download][type] = git
projects[views_rss][download][url] = http://git.drupal.org/project/views_rss.git
projects[views_rss][download][revision] = 807710f46accbdd795b4463ff6dbd726ab6f19fb

; DraggableViews, has no stable 7.x release yet.
projects[draggableviews][type] = module
projects[draggableviews][download][type] = git
projects[draggableviews][download][url] = http://git.drupal.org/project/draggableviews.git
projects[draggableviews][download][revision] = 9677bc18b7255e13c33ac3cca48732b855c6817d

; We run with the dev version to get exportability.
projects[wysiwyg][type] = module
projects[wysiwyg][download][type] = git
projects[wysiwyg][download][url] = http://git.drupal.org/project/wysiwyg.git
projects[wysiwyg][download][revision] = 60ea63c0b609f89878dfdf87616f3a88268b5217

; Dev version needed since we need to patch it.
projects[menu_block][type] = module
projects[menu_block][download][type] = git
projects[menu_block][download][url] = http://git.drupal.org/project/menu_block.git
projects[menu_block][download][revision] = 00a45217f8ec87d14b436e8ad88e8799f964be32

; Dev version needed for better support for caching and template suggestions.
projects[panels][type] = module
projects[panels][download][type] = git
projects[panels][download][url] = http://git.drupal.org/project/panels.git
projects[panels][download][revision] = dbe41ce

; Parallel development
projects[ns_core][type] = module
projects[ns_core][download][type] = git
projects[ns_core][download][url] = http://git.drupal.org/project/ns_core.git
projects[ns_core][download][branch] = 7.x-2.x

; We need to use the dev version in order to work with media 2.x
projects[media_youtube][type] = module
projects[media_youtube][download][type] = git
projects[media_youtube][download][url] = http://git.drupal.org/project/media_youtube.git
projects[media_youtube][download][revision] = 0cf05da

; We need the latest version to not interfere with features.
projects[defaultconfig][type] = module
projects[defaultconfig][download][type] = git
projects[defaultconfig][download][url] = http://git.drupal.org/project/defaultconfig.git
projects[defaultconfig][download][revision] = ad6090e

; Dev version since no stable version is available.
projects[pathfilter][type] = module
projects[pathfilter][download][type] = git
projects[pathfilter][download][url] = http://git.drupal.org/project/pathfilter.git
projects[pathfilter][download][revision] = 42c6e37

; Needed for bug fixes.
projects[admin_menu][type] = module
projects[admin_menu][download][type] = git
projects[admin_menu][download][url] = http://git.drupal.org/project/admin_menu.git
projects[admin_menu][download][revision] = f6d25420fc66f7f57cc8240970bdbade64215c51

; Needed to support views 3.0-rc3
projects[references][type] = module
projects[references][download][type] = git
projects[references][download][url] = http://git.drupal.org/project/references.git
projects[references][download][revision] = e006865

; Libraries

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.tar.gz
libraries[ckeditor][destination] = libraries

libraries[jquery.cycle][download][type] = get
libraries[jquery.cycle][download][url] = http://malsup.com/jquery/cycle/release/jquery.cycle.zip?v2.99
libraries[jquery.cycle][destination] = libraries

; Patches

; http://drupal.org/node/624018#comment-4519502
projects[wysiwyg][patch][] = http://drupal.org/files/issues/wysiwyg-entity-exportables-624018-176_1.patch

; http://drupal.org/node/1119948#comment-4599770
projects[views_rss][patch][] = http://drupal.org/files/issues/drupal_7_port-1119948-7.patch

; http://drupal.org/node/1105372
projects[menu_block][patch][] = http://drupal.org/files/issues/1105372-add-menu-tree-ctools-content-type-d7-5.patch

; http://drupal.org/node/1247292
projects[views][patch][] = http://drupal.org/files/issues/node_revision_display_content.patch

; http://drupal.org/node/1173978
projects[panels][patch][] = http://drupal.org/files/1173978-panels-undefined-variable-tokens-5.patch

; http://drupal.org/node/1288648
projects[features][patch][] = http://drupal.org/files/issues/ctools_component_features_api-define-your-own-components.patch

; http://drupal.org/node/1311828
projects[media][patch][] = http://drupal.org/files/media-install-error-1311828-28.patch

