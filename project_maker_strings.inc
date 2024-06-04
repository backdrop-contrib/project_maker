<?php
/**
 * @file
 * Provides primary Backdrop hook implementations.
 */

/**
 * Implements hook_permission().
 */

/**
 * Converts files in a theme directory.
 */
function project_maker_replacement_strings($string, $replacestring, $replacestring2 = '', $replacestring3 = '') {
$strings = array();
$strings['module'] = <<<EOD
<?php
/**
 * @file
 * $replacestring.
 */

EOD;

$strings['install'] = <<<EOD
<?php
/**
 * @file
 * Install, update and uninstall functions for the $replacestring module.
 */

EOD;

$strings['theme'] = <<<EOD
<?php
/**
 * @file
 * Theme functions for the $replacestring module.
 */

EOD;

$strings['admin'] = <<<EOD
<?php
/**
 * @file
 * Admin page callbacks for the $replacestring module.
 */

EOD;

$strings['js'] = <<<EOD
/**
 * @file
 * Javascript behaviours for the $replacestring module.
 */

EOD;

$strings['css'] = <<<EOD
/**
 * @file
 * Provides CSS styles for the $replacestring module.
 */

EOD;

$strings['hook_menu'] = <<<EOD
/**
 * Implements hook_menu().
 */
function {$replacestring}_menu() {
  \$items['$replacestring'] = array(
    'title' => 'Example Page',
    'page callback' => 'example_page',
    'access arguments' => array('access content'),
    'type' => MENU_SUGGESTED_ITEM,
  );

  return \$items;
}

EOD;

$strings['hook_permission'] = <<<EOD
/**
 * Implements hook_permission().
 */
function {$replacestring}_permission() {
  return array(
    'administer $replacestring' => array(
      'title' => t('Administer $replacestring'),
      'description' => t('Perform administration tasks for $replacestring.'),
    ),
  );
}

EOD;

$strings['hook_enable'] = <<<EOD
/**
 * Implements hook_enable().
 */
function {$replacestring}_enable() {

}

EOD;

$strings['theme_settings'] = <<<EOD
<?php
/**
 * @file
 * theme-settings.php
 *
 * Theme settings file for $replacestring.
 */

EOD;

$strings['blank_layout_template'] = <<<EOD
<?php
/**
 * @file
 * Template for the $replacestring2 layout.
 *
 * Variables:
 * - \$title: The page title, for use in the actual HTML content.
 * - \$messages: Status and error messages. Should be displayed prominently.
 * - \$tabs: Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node.)
 * - \$action_links: Array of actions local to the page, such as 'Add menu' on
 *   the menu administration interface.
 * - \$classes: Array of CSS classes to be added to the layout wrapper.
 * - \$attributes: Array of additional HTML attributes to be added to the layout
 *     wrapper. Flatten using backdrop_attributes().
 * - \$content: An array of content, each item in the array is keyed to one
 *   region of the layout. This layout supports the following sections:
 */
?>
<div class="layout--$replacestring <?php print implode(' ', \$classes); ?>"<?php print backdrop_attributes(\$attributes); ?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>

</div><!-- /.layout--$replacestring -->
EOD;

  return $strings[$string] . "\r\n";
}
