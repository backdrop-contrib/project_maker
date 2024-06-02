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
function project_maker_replacement_strings($string, $replacestring) {
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

  return $strings[$string] . "\r\n";
}
