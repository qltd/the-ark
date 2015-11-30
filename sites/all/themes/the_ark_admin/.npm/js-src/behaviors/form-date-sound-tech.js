(function ($) {
  var dateUTCToLocal = function (seconds) {
    if (!seconds) return new Date();
    var ms = parseInt(seconds) * 1000
      , raw = new Date(ms)
      , rawTime = [raw.getHours(), raw.getMinutes(), raw.getSeconds()];
    console.log(raw.toDateString() + ' ' + rawTime.join(':') + ' GMT');
    return new Date(raw.toDateString() + ' ' + rawTime.join(':') + ' GMT');
  };

  Drupal.admin.behaviors.theArkAdminFormDateSoundTech = function () {
    var soundTechForm = $('#sound-tech-node-form');
    if (soundTechForm.length === 0) return;

    var dateField = $('.form-item-field-date-und-0-value-date .form-text')
      , timeField = $('.form-item-field-date-und-0-value-time .form-text')
      , eventDateRaw = $.getQueryParameters().field_date;

    if (dateField.length === 0 || !eventDateRaw || dateField.val()) return;

    var eventDate = dateUTCToLocal(eventDateRaw)
      , eventDateFormatted = (eventDate.getMonth() + 1) + '/' + eventDate.getDate() + '/' + eventDate.getFullYear();

    timeField.val('05:00pm');
    dateField.val(eventDateFormatted);
  };
})(jQuery);
